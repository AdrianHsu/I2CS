#include <iostream>
#include <cstdlib>
using namespace std;

//#define lu_MAX   4294967295 //2^64
//#define int_MAX  2147483647 //2^32
typedef unsigned long long int longint;

longint findD(longint e, longint phi)
{
    longint s = 0, new_s = 1;
    longint r = phi, new_r = e;
    while(new_r != 0)
    {
        longint q = r / new_r;
        longint tmp;
        //for s
        tmp = new_s;
        new_s = ( s + phi - (q * new_s % phi)) % phi;
        s = tmp;
        //for r
        tmp = new_r;
        new_r = r - q * new_r;
        r = tmp;
    }
    return s;
}
