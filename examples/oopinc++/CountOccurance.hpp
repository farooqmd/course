#ifndef COUNTOCCURANCE_HPP
#define COUNTOCCURANCE_HPP

class CountOccurance {
  static int cnt;
public:
  CountOccurance() { ++cnt; }
  ~CountOccurance() { --cnt; }

  static int getCount() { return cnt; }
};

#endif
