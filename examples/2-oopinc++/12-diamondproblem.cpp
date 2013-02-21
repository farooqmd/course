#include <iostream>
#include <string>
using namespace std;

/* illustration of multiple inheritance and the diamond problem.
              Person
	      |    |
	Student    Teacher
              |    |
            StudyingTeacher
 */

class Person {
protected:
  string name;
public:
  Person(const string &_name): name(_name) { }
  virtual string getNameAndTitle() { return name; }
};

class Teacher: virtual public Person {
public:
  Teacher(const string &_name): Person(_name) { }
  virtual string getNameAndTitle() { return string("Prof. ") + name; }
};

class Student: virtual public Person {
public:
  Student(const string &_name): Person(_name) { }
  virtual string getNameAndTitle() { return string("Cand. ") + name; }
};

class StudyingTeacher: virtual public Teacher, virtual public Student {
public:
  StudyingTeacher(const string &_name): Person(_name),
					Teacher(_name), Student(_name) {}
  // specify explicitely what we want
  virtual string getNameAndTitle() { return Teacher::getNameAndTitle(); }
};

void printGeneric(Person &person) {
  cout << person.getNameAndTitle() << endl;
}

int main() {
  Person axel("Axel");
  Student bob("Bob");
  Teacher chris("Chris");
  StudyingTeacher dirk("Dirk");
  cout << "axel: "  << axel.getNameAndTitle() << endl;
  printGeneric(axel);
  cout << "bob: "   << bob.getNameAndTitle() << endl;
  printGeneric(bob);
  cout << "chris: " << chris.getNameAndTitle() << endl;
  printGeneric(chris);
  cout << "dirk: "  << dirk.getNameAndTitle() << endl;
  printGeneric(dirk);

  return 0;
}
