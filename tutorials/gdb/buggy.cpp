<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<string>
=======
#include <iostream>
#include <string>
#include <vector>
>>>>>>> origin/master
using namespace std;

string bottles(int i) {
  string s;
<<<<<<< HEAD
  switch (i) {
  case 0: s = " bottle(s) of beer on the wall, ";
	  break;
  case 1: s = " bottle(s) of beer.";
	  break;
  case 2: s = " bottle(s) of beer on the wall.";
	  break;
=======
  switch(i) {
  case 0: 
    s = " bottle(s) of beer on the wall, "; 
    break;
  case 1: 
    s = " bottle(s) of beer."; 
    break;
  case 2: 
    s = " bottle(s) of beer on the wall."; 
    break;
>>>>>>> origin/master
  }
  return s;
}

<<<<<<< HEAD
void reverse_vector(vector<int> &v) {
  int tmp, size=v.size();
  int sizehalf=size/2; 
=======
vector <int> reverse_vector(vector <int> &v) {
  vector<int> vnew;
  
  for (int i = v.size()-1; i > 0; i--)
    vnew.push_back(v[i]);
>>>>>>> origin/master

  for (int i=0; i<sizehalf; i++){
    tmp=v[i];
    v[i]=v[size-i-1];
    v[size-i-1]=tmp;
  }
}

int main() {
  vector<int> v;

  // create vector of number 0..99
<<<<<<< HEAD
  for (int i = 0; i < 10; i++)
    v.push_back(i);

  // reverse vector
  reverse_vector(v);

  for (int i : v) {
=======
  for (int i = 0; i < 100; i++) {
    v.push_back(i);
  }

  // reverse vector
  vector<int>  vnew = reverse_vector(v);

  for (int i : vnew) {
>>>>>>> origin/master
    cout << i << bottles(0) << endl;
    cout << i << bottles(1) << endl;
    cout << (i-1) << bottles(2) << endl;
  }

  return 0;
}
