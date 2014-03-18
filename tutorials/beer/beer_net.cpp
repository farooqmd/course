#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>

using namespace std;

void replace_all(string &haystack, 
                 const string needle, 
                 const string replacement) {
  for (size_t pos = haystack.find(needle);
       pos != string::npos; 
       pos = haystack.find(needle, pos)) 
    haystack.replace(pos, 2, replacement);
}

int main(int argc, char *argv[]) {
  if (argc < 3) return 2;
  zmqpp::context context;

  cout << "Waiting for incoming connection on " << argv[1] 
       << "..." << endl;
  zmqpp::socket pull_socket (context, zmqpp::socket_type::pull);
  pull_socket.bind(argv[1]);

  cout << "Opening connection to " << argv[2] 
       << "..." << endl;
  zmqpp::socket push_socket (context, zmqpp::socket_type::push);
  push_socket.connect(argv[2]);

  while (true) {
    cout << "Waiting to receive message..." << endl;

    int number;
    string text;
    {
      zmqpp::message message;
      pull_socket.receive(message);
      message >> number >> text;
      
      if (number == 0) break;

      // Make a copy of the string and replace it
      string s = text;
      replace_all(s, "$1", to_string(number));
      number--;
      replace_all(s, "$2", to_string(number));
      cout << s << endl;
    }

    {
      cout << "Passing on the message..." << endl;
      zmqpp::message message;
      message << number << text;
      push_socket.send(message);

      if (number == 0) break;
    }
  }

  return 0;
}
