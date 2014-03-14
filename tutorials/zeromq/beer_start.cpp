#include <zmqpp.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) return 2;
  zmqpp::context context;
  
  std::cout << "Opening connection to " << argv[1] << std::endl;
  zmqpp::socket push_socket (context, zmqpp::socket_type::push);
  push_socket.connect(argv[1]);

  std::cout << "Waiting for incoming connection on " << argv[2] 
            << "..." << std::endl;
  zmqpp::socket pull_socket (context, zmqpp::socket_type::pull);
  pull_socket.bind(argv[2]);

  int number = 99;
  std::string text = " bottles of beer on the wall. Take one down, pass it around. ";

  zmqpp::message message;
  message << number << text;
  push_socket.send(message);
  std::cout << "Sending: \"" << number << text << "\"" << std::endl;

  pull_socket.receive(message);
  message.get(number, 0);
  message.get(text, 1);
  std::cout << "Received: \"" << number << text << "\"" << std::endl;

  return 0;
}
