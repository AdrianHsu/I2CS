#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

typedef unsigned long long int longint;
#define lu_MAX   4294967295 //2^64
#define int_MAX  2147483647 //2^32
#define _8_BIT 256

longint string2Int(const string&);
longint _pow(longint, longint);
string _result(longint);

longint N = 0;
longint d = 0;
int main()
{
    //printf("%d", sizeof(unsigned long long int));
    ifstream ifs;
    string _N_d = "private_key.txt";
    ifs.open(_N_d.c_str(), ios::binary); 
    ifs >> N >> d;

    ifs.close();
    ofstream ofs;

    string input = "secret.txt";
    string output = "message.txt";

    ifs.open(input.c_str(), ios::in);
    ofs.open(output.c_str(), ios::out);
    if(!ifs.is_open())
        printf("ERROR: LOAD FILE FAILED.");

    string s;
    while(getline(ifs, s))
    {
        longint rsa = _pow(string2Int(s), d);
        ofs << _result(rsa);
    }
    ifs.close();
    ofs.close();
    return 0;
}
longint string2Int(const string& str)
{
    longint num = 0;
    for (longint i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            num *= 10;
            num += int(str[i] - '0');
        }
    }
    return num;
} 
//s^d = m (mol N)
longint _pow(longint s, longint d)
{
    if(d == 1)
        return s;
    if(d % 2 == 0)
        return ( _pow(s, d / 2) *  _pow(s, d / 2) ) % N;
    else
        return _pow(s, (d - 1) / 2) * _pow(s, (d + 1) / 2) % N;
}
string _result(longint num)
{
    string str;
    if(num % _8_BIT == 0)
    {
        str += (char)(num / _8_BIT);
    }
    else
    {
        str += (char)(num / _8_BIT);
        num %= _8_BIT;
        str += (char)num;
    }
    return str;
}
