#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) return 2;
  zmqpp::context context;
  
  std::cout << "Opening connection to " << argv[1] << std::endl;
  zmqpp::socket push_socket (context, zmqpp::socket_type::push);
  push_socket.connect(argv[1]);

  {
    zmqpp::message message;
    message << 99 
            << "$1 bottles of beer on the wall. $1 bottles of beer.\n"
               "Take one down and pass it around, $2 bottles of beer.\n";
    push_socket.send(message);
  }

  std::cout << "Finished." << std::endl;
  return 0;
}
