// This is a comment

/* This is a multi-line comment, 
   that can go on on the next line
*/

// Possible extensions:
// * .cpp, .cxx, .cc, .C, .c++ for source files
// * .hpp, .hxx, .hh, .H, .h++ for header files (see later)

// Compile this file with:
// > g++ -o helloworld 01-helloworld.cpp
// * "-o" defines the name of the executable

// Better:
// > g++ -Wall -O3 --std=c++0x -o helloworld 01-helloworld.cpp
// * "-Wall" turns on to output all possible warnings
// * "-O3" turns on optimization
// * "--std=c++0x" turns on ISO-standard C++11 
//   (formerly known as "C++0x") 

// Ignore the following two lines for now
#include <iostream>
using namespace std;

// * define a FUNCTION
// * RETURN TYPE is int
// * no parameter (hence "()")
// * everything between "{" and "}" is FUNCTION BODY
// * each statement ends with ";"
// * main() must exist in every program
int main()
{
  // * "cout" and "endl" are from the C++ STANDARD LIBRARY
  // * "cout" (and "endl") is an OBJECT type
  // * "cout" represents the standard output as a STREAM
  // * OPERATOR "<<" outputs data (here: "Hello, World!" to the stream
  // * "endl" (end line) ends the line of output and flushes the
  //   stream (i.e. forces the output)
  cout << "Hello, World!" << endl;

  // * the function returns "0"
  // * the return value is passed to the shell
  return 0;
}

// * Note that in C "<<" is bitwise left-shift operator
// * In C++, functions (and operators) can be OVERLOADED, i.e. they
//   work differently depending on their parameters (resp. their
//   operands)
// * The operator "<<" sends the data on the right-hand side (RHS)
//   to the stream on the left-hand side (LHS)
// * It returns the (modified) stream object...
// * ...which is the lhs of the second "<<"

// * "#include <iostream>" makes the variables and functions defined
//   in the header "iostream" of the C++ standard library known (see
//   later)
// * "using namespace std" tells the compiler that all variables and
//   functions from the NAMESPACE std can be used (see later)
