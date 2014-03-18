#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float myroot(float x) {
  if (x < 0.0) throw string("Can't take root of a negative number!");
  return sqrt(x);
}

vector<float>* listofroots(vector <float> &xs) {
  vector<float> *results = new vector<float>();

  try {

    for (auto x: xs)
      results->push_back(myroot(x));

  } catch (string &ex) {
    // Clean up results before rethrowing the exception
    delete results;
    // Throw in a "catch" will just thow the exception again
    throw;
  }

  return results;
}

int main() {

  try {
    vector<float> xs = {1.0, 2.0, 3.0};
    vector<float>* roots = listofroots(xs);
    for (auto i: *roots) cout << i << endl;

    vector<float> xs2 = {1.0, 2.0, 3.0, -1.0};
    vector<float>* roots2 = listofroots(xs2);
    for (auto i: *roots2) cout << i << endl;

  } catch (string& ex) {
    cout << "Caught exception: " << ex << endl;
  }
}
