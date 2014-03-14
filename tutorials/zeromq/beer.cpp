#include <zmqpp.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) return 2;
  zmqpp::context context;

  std::cout << "Waiting for incoming connection on " << argv[1] 
            << "..." << std::endl;
  zmqpp::socket pull_socket (context, zmqpp::socket_type::pull);
  pull_socket.bind(argv[1]);

  std::cout << "Opening connection to " << argv[2] 
            << "..." << std::endl;
  zmqpp::socket push_socket (context, zmqpp::socket_type::push);
  push_socket.connect(argv[2]);

  while (true) {
    std::cout << "Waiting to receive message..." << std::endl;
    
    int number;
    std::string text;

    {
      zmqpp::message message;
      pull_socket.receive(message);
      message >> number >> text;
    }

    std::cout << "Received: \"" << number << text << "\"" << std::endl;
    number--;

    {
      zmqpp::message message;
      message << number << text;
      std::cout << "Sending: \"" << number << text << "\"" << std::endl;
      push_socket.send(message);
    }
  }

  return 0;
}
