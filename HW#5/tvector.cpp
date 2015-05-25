#include "myvector.h"
#include <iostream>
using namespace std;

#ifndef _T_VECTOR_H
#define _T_VECTOR_H

template <int T>
class TVector
{
    public:
        TVector();
        TVector(const TVector &);
        ~TVector();
        const TVector& operator=(const TVector);
        int getLength() const;
        TVector& set(const int, const double);
        double get(const int) const;
        TVector operator+(const TVector&) const;
        double operator*(const TVector& ) const;
        Tvector& resize(const int);

        template <int J>
        friend ostream& operator<<(ostream&, const TVector<J> &);

    private:
        MyVector a;
};

template<int T>
TVector<T>::TVector()
{   
    a = MyVector(T); 
}

template<int T>
TVector<T>::TVector(const TVector<T>& p)
    : a(p.a){}

template<int T>
const TVector<T>& TVector<T>::operator=(const TVector<T> p)
{   
    a = p.a;
    return (*this);
}

template<int T>
int TVector<T>::getLength() const
{   
    return a.getLength();
}

template<int T>
double TVector<T>::get(const int pos) const
{   
    return a.get(pos);
}

template<int T>
TVector<T>& TVector<T>::set(const int pos, const double value)
{   
    a.set(pos, value);
    return (*this);
}

template<int T>
TVector<T> TVector<T>::operator+(const TVector<T> p) const
{   
    TVector<T> ans;
    ans.a = a + p.a;
    return ans;
}

template<int T>
double TVector<T>::operator*(const TVector<T> p) const
{   
    return a * p.a;
}

template<int T>
Tvector& TVector<T>::resize(const int p)
{   
    std::cout << "Resize not allowed" << std::endl;
    return *this;
}

template<int T>
TVector<T>::~TVector()
{}

template<int T>
ostream& operator<<(ostream& output, const TVector<T>& p)
{   
    output << p.a;
    return output;
}

#endif
