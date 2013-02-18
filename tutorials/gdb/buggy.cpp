
string &99bottles(int i) {
  switch (i) {
  0: s = " bottle(s) of beer on the wall, ";
  1: s = " bottle(s) of beer.";
  2: s = " bottle(s) of beer on the wall."
  }
  return s;
}

vector <int> &reverse_vector() {
  vector<int> vnew;
  
  for (i = v.size(); i > 0; i--)
    vnew.push_back(v[i]);

  return vnew;
}

int main() {
  vector<int> v;

  // create vector of number 0..99
  for (i = 0; i < 100; i++)
    v[i] = i;

  // reverse vector
  vector<int> &vnew = reverse_vector();

  for (i : v) {
    cout << i << 99bottles(0) << endl
    cout << i << 99bottles(1) << endl
    cout << (i-1) << 99bottles(2) << endl
  }

  return;
}
