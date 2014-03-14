#include "mysqrt.hpp"
#include <stdexcept>
#include <cmath>

double f(double r, double x) {
  return r*r-x;
}

double fp(double r) {
  return 2*r;
}

double mysqrt(double x) {

  if (std::abs(x) < 1.e-10) return 0.0;
  if (x < 0.0) throw std::logic_error("Don't call with negative numbers!");

  // solve r**2 - x = 0 via Newton's method
  double d = 1.0;
  double r = x;
  
  while (d > 1.e-10) {
    d = f(r,x)/fp(r);
    r -= d;
  }

  return r;
}
