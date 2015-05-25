#include <iostream>
#include "myvector.h"
#include "tvector.h"
#include "tvector.cpp"

using namespace std;

int main()
{
    TVector<3> a,b,c; b.set(0,0).set(1,1).set(2,2); 
    
    c = b;
    a = b+c;
    cout << a << endl;
    a.set(0, 0.0).set(1, 0.1).set(2, 0.2);

    cout << a << endl;
    cout << a.get(1) << endl;
    cout << a.getLength() << endl;

    c = b = a;            // test copier

    cout << b << endl;
    cout << c << endl;

    TVector<3> d(c);  // test copy constructor
    cout << d << endl;

    cout << c*d << endl;     // inner product
    cout << a+b+c << endl;

    cout << a+b+c << endl;
}

