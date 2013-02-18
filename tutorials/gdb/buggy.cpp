#include <string>
#include <vector>
#include <iostream>
using namespace std;

string bottles(int i) {
  string s = "";
  switch(i) {
  case 0:
    s = " bottle(s) of beer on the wall, ";
    break;
  case 1:
    s = " bottle(s) of beer.";
    break;
  case 2:
    s = " bottle(s) of beer on the wall.";
  }
  return s;
}

vector <int> reverse_vector(vector<int> v) {
  vector<int> vnew;

  for (int i = v.size(); i > 0; i--)
    vnew.push_back(v[i]);

  return vnew;
}

int main() {
  vector<int> v;

  // create vector of number 0..99
  for (int i = 0; i < 100; i++)
    v.push_back(i);

  // reverse vector
  vector<int> vnew = reverse_vector(v);

  for (int i : vnew) {
    cout << i << bottles(0) << endl;
    cout << i << bottles(1) << endl;
    cout << (i-1) << bottles(2) << endl;
  }

  return 0;
}
