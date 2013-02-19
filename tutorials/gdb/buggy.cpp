#include<iostream>
#include<vector>
#include<string>
using namespace std;

string bottles(int i) {
  string s;
  switch (i) {
  case 0: s = " bottle(s) of beer on the wall, ";
	  break;
  case 1: s = " bottle(s) of beer.";
	  break;
  case 2: s = " bottle(s) of beer on the wall.";
	  break;
  }
  return s;
}

void reverse_vector(vector<int> &v) {
  int tmp, size=v.size();
  int sizehalf=size/2; 

  for (int i=0; i<sizehalf; i++){
    tmp=v[i];
    v[i]=v[size-i-1];
    v[size-i-1]=tmp;
  }
}

int main() {
  vector<int> v;

  // create vector of number 0..99
  for (int i = 0; i < 10; i++)
    v.push_back(i);

  // reverse vector
  reverse_vector(v);

  for (int i : v) {
    cout << i << bottles(0) << endl;
    cout << i << bottles(1) << endl;
    cout << (i-1) << bottles(2) << endl;
  }

  return 0;
}
