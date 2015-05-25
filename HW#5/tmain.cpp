#include <iostream>
#include "myvector.h"
#include "tvector.cpp"	// test for duplicated inclusion

using namespace std;

int main()
{
    TVector<3> a,b,c; b.set(0,0).set(1,1).set(2,2); 
    c = b;
    a = b+c;
    cout << a;

}

