#include <iostream>
using namespace std;
#include "CountOccurance.hpp"

// using static allocation on the stack
void testStack() {
  for (int i = 0; i < 10; ++i) {
    CountOccurance piece;
    // here, piece is destroyed automatically
  }
}

// using more complex allocation on the stack
void testStackComplex() {
  CountOccurance fixedpiece;
  for (int i = 0; i < 10; ++i) {
    CountOccurance piece;
    fixedpiece = piece;
    cout << "inbetween:" << CountOccurance::getCount() << endl;
    // here, piece is destroyed automatically
  }
}

void testNewCorrect() {
  for (int i = 0; i < 10; ++i) {
    CountOccurance *piecePtr = new CountOccurance;
    delete piecePtr;
    // without this, the older pieces remain, but inaccessible
  }
}

void testNewWrong() {
  CountOccurance *piecePtr;
  for (int i = 0; i < 10; ++i) {
    piecePtr = new CountOccurance;
    // the older pieces remain, but inaccessible
    // this makes it even worse...
    //delete piecePtr;
  }
  delete piecePtr;
}

int main()
{
  testStack();
  cout << "left: " << CountOccurance::getCount() << endl;
  testStackComplex();
  cout << "left: " << CountOccurance::getCount() << endl;
  testNewCorrect();
  cout << "left: " << CountOccurance::getCount() << endl;
  testNewWrong();
  cout << "left: " << CountOccurance::getCount() << endl;
  
}
