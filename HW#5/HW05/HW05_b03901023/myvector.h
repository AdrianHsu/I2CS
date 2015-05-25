#include <iostream>
using namespace std;

#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H


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
        MyVector& set(const int ,const double);
        double get(const int) const;
        //(9) Operator+ and operator* (inner product)
        MyVector operator+(const MyVector& ) const;
        double operator*(const MyVector& ) const;
        //(10) resize() (content in data[] can be destroyed)
        MyVector& resize(const int);

        //(8) Ostream (for cout)
        friend ostream& operator<<(ostream&, const MyVector &);

    private:
        int length;
        double *data;
};
#endif
