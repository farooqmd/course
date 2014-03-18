#include <iostream>
using namespace std;

// * Defining the basic data types
int main() {
  // Definition without initialization:
  bool truth;
  char protein;
  int carbohydrates;
  float fiber;
  double fat;

  // with specifiers
  unsigned int pos;
  long int large;
  long double reallylarge;

  cout 
    << "bool=" << sizeof(bool) << endl
    << "char=" << sizeof(protein) << endl
    << "int=" << sizeof(carbohydrates) << endl
    << "float=" << sizeof(fiber) << endl
    << "double=" << sizeof(fat) << endl
    << "unsigned int=" << sizeof(pos) << endl
    << "long int=" << sizeof(large) << endl
    << "long double=" << sizeof(reallylarge) << endl;

  // Simultaneous definition & initialization:
  bool truth2 = true;
  char pizza = 'A', pop = 'Z';
  int dongdings = 100, twinkles = 150, 
    heehos = 200;
  float chocolate = 3.14159;
  // Exponential notation:
  double fudge_ripple = 6e-4; 

}
