#include <iostream>
using namespace std;

// enumeration type
// * basically like an integer
// * makes code more readable
enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

int working_time(Weekday day) {
  switch (day) {
  case Monday:
  case Tuesday:
  case Wednesday:
  case Thursday:
  case Friday:
    return 8;
  case Saturday:
  case Sunday:
    return 0;
  }
  return 0;
}

int main() {
  cout << "Working time on Monday is " << working_time(Monday) << " hours." << endl;
  cout << "Working time on Sunday is " << working_time(Sunday) << " hours." << endl;

  Weekday myday = Tuesday;
  cout << "Working time on my day is " << working_time(myday) << " hours." << endl;
}
