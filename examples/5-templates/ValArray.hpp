#ifndef VALARRAY_HPP
#define VALARRAY_HPP

/* const size array, with default length 3. */
template<typename T, int size = 3>
class ValArray {
  T data[size];
public:
  ValArray() {}
  ValArray(const ValArray &v2);

  int getSize() const { return size; }

  T       &operator[](int i)       { return data[i]; }
  const T &operator[](int i) const { return data[i]; }
  
  // classes can contain types and classes
  typedef T *iterator;
  typedef const T *const_iterator;

  iterator begin() { return data; }
  iterator end()   { return data + size; }

  const_iterator begin() const { return data; }
  const_iterator end()   const { return data + size; }
};

template<typename T, int size>
ValArray<T, size>::ValArray(const ValArray &v2)
{
  for (int i = 0; i < size; ++i) {
    data[i] = v2[i];
  }
}

#endif
