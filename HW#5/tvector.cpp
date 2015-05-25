#ifndef _TVECTOR_
#define _TVECTOR_

#include "myvector.h"
#include <iostream>

template <int T>
class TVector
{
public:
  template <int J> friend std::ostream& operator<<(std::ostream&, const TVector<J>&);
  TVector();
  TVector(const TVector&);
  TVector& operator=(const TVector);
  int getLength() const;
  double get(const int) const;
  TVector& set(const int, const double);
  TVector operator+(const TVector) const;
  double operator*(const TVector) const;
  void resize(const int);
  ~TVector();
private:
  MyVector a;
};

template<int T>
TVector<T>::TVector()
{   a = MyVector(T);
}

template<int T>
TVector<T>::TVector(const TVector<T>& p): a(p.a)
{
}

template<int T>
TVector<T>& TVector<T>::operator=(const TVector<T> p)
{   a = p.a;
    return (*this);
}

template<int T>
int TVector<T>::getLength() const
{   return a.getLength();
}

template<int T>
double TVector<T>::get(const int pos) const
{   return a.get(pos);
}

template<int T>
TVector<T>& TVector<T>::set(const int pos, const double value)
{   a.set(pos, value);
    return (*this);
}

template<int T>
TVector<T> TVector<T>::operator+(const TVector<T> p) const
{   TVector<T> ans;
    ans.a = a + p.a;
    return ans;
}

template<int T>
double TVector<T>::operator*(const TVector<T> p) const
{   return a * p.a;
}

template<int T>
void TVector<T>::resize(const int p)
{   std::cout << "Resize not allowed" << std::endl;
}

template<int T>
TVector<T>::~TVector()
{
}

template<int T>
std::ostream& operator<<(std::ostream& output, const TVector<T>& p)
{   output << p.a;
    return output;
}

#endif
