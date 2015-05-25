#include <iostream>
using namespace std;

#ifndef _T_VECTOR_H
#define _T_VECTOR_H


class MyVector {

    public:

        //(1) Default constructor
        MyVector();
        //(2) Copy constructor
        MyVector(const MyVector &);
        //(3) Constructor that take one integer argument.
        MyVector(int);
        //(4) Destructor
        ~MyVector();
        //(5) Copier
        const MyVector& operator=(const MyVector &);
        //(6) Getter for length
        int getLength() const;
        //(7) Getter and setter for data[]
        MyVector& set(int , double);
        double get(int) const;
        //(9) Operator+ and operator* (inner product)
        MyVector operator+(const MyVector& ) const;
        double operator*(const MyVector& );
        //(10) resize() (content in data[] can be destroyed)
        MyVector& resize(int);

        //(8) Ostream (for cout)
        friend ostream& operator<<(ostream&, const MyVector &);

    private:
        int length;
        double *data;
};

template <int N>
class TVector : MyVector {

    static const int N;

};
#endif
