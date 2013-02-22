#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T>
class Vector {
  T *data;
  int size;
public:
  Vector(int len);
  Vector(const Vector &v2);

  int getSize() const { return size; }

  T       &operator[](int i)       { return data[i]; }
  const T &operator[](int i) const { return data[i]; }

private:
  void allocate(int len);
};

template<typename T>
void Vector<T>::allocate(int len) {
  if (data) {
    delete[] data;
  }
  data = new T[len];
  size = len;
}

template<typename T>
Vector<T>::Vector(int len): data(0)
{
  allocate(len);
}

template<typename T>
Vector<T>::Vector(const Vector &v2): data(0)
{
  allocate(v2.getSize());
  for (int i = 0; i < size; ++i) {
    data[i] = v2[i];
  }
}

#endif
