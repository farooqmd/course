#include "Integer.hpp"

void Integer::setValue(int _value) {
  // here, we can use value without qualification
  value = _value;

  // looks strange, but also works:
  // this->value = _value;
}
