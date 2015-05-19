#include "myvector.h"
#include "tvector.h"

//(1) Default constructor
MyVector::MyVector()
    :length(0), data(NULL){};
//(2) Copy constructor
    MyVector::MyVector(const MyVector& target)
:length(0), data(NULL)
{
    resize(target.getLength());
    for(int i = 0; i < length; i++)
        data[i] = target.get(i);
}
//(3) Constructor that take one integer argument.
MyVector::MyVector(int _length)
    :length(_length), data( new double [_length] ){};
//(4) Destructor
MyVector::~MyVector()
{
    delete [] data;
}
//(5) Copier
const MyVector& MyVector::operator=(const MyVector& target)
{
    resize(target.getLength());
    for(int i = 0; i < length; i++)
        data[i] = target.get(i);
    return *this;
}
//(6) Getter for length
int MyVector::getLength() const
{
    return length;
}
//(7) Getter and setter for data[]
MyVector& MyVector::set(int i, double input)
{
    data[i] = input;
    return *this;
}
double MyVector::get(int i) const
{
    return data[i];
}
//(9) Operator+ and operator* (inner product)
MyVector MyVector::operator+(const MyVector& target) const
{
    MyVector out(length);
    for(int i = 0; i < length; i++)
        out.data[i] = data[i] + target.get(i);
    return out;
}
double MyVector::operator*(const MyVector& target)
{
    double result = 0.0;
    for(int i = 0; i < length; i++)
        result += data[i] * target.get(i);
    return result;
}
//(10) resize() (content in data[] can be destroyed)
MyVector& MyVector::resize(int size)
{
    double *tmp = new double [size];
    if(size <= length)
    {
        for(int i = 0; i < size; i++)
        {
            tmp[i] = data[i];
        }
    }
    else
    {
        for(int i = 0; i < length; i++)
            tmp[i] = data[i];
        for(int i = length; i < size; i++)
            tmp[i] = 0;
    }
    if(data != NULL)
        delete [] data;
    length = size;
    data = tmp;
    return *this;
}
//(8) Ostream (for cout)
ostream& operator<<(ostream& out, const MyVector & target)
{
    out << "(";
    for(int i = 0; i < target.getLength(); i++)
    {
        out << target.data[i];
        if(i < target.getLength() - 1)
            out << ",";
    }
    out << ")";
    return out;
}
