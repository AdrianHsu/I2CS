#include <iostream>
#include "myvector.h"
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
        TVector operator+(const TVector& ) const;
        double operator*(const TVector& ) const;
        TVector& resize(const int);

        template <int U>
        friend ostream& operator<<(ostream&, const TVector<U> &);

    private:
        MyVector vec;
};
#endif
