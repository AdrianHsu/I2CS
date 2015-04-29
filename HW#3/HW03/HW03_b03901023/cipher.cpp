#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

#define _8_BIT 256
typedef unsigned long long int longint;

longint find_m(const longint, const longint); //function overloading
longint find_m(const longint);
longint _pow(longint, longint);

longint RSA(const longint); 

longint N = 0;
longint e = 0;
int main()
{
    //printf("%d", sizeof(unsigned long long int));
    ifstream ifs;
    string _N_e = "public_key.txt";
    ifs.open(_N_e.c_str(), ios::binary); 
    ifs >> N >> e;

    ifs.close();
    ofstream ofs;

    string input = "plain.txt";
    string output = "secret.txt";

    ifs.open(input.c_str(), ios::in);
    ofs.open(output.c_str(), ios::out);
    if(!ifs.is_open())
        printf("ERROR: LOAD FILE FAILED.");

    string line;
    while(getline(ifs, line))
    {
        const int STR_LEN = strlen(line.c_str()); //length < 10000 
       
        int i = 0;
        while(i < STR_LEN)
        {
            if(i != STR_LEN - 1)
                ofs << RSA( find_m(line[i], line[i + 1])) << endl;
            else
                ofs << RSA( find_m(line[i])) << endl;
            i += 2;
        }
    }
    ifs.close();
    ofs.close();
    return 0;
}
longint find_m(const longint _p, const longint q)
{
    return _p * _8_BIT + q;
}
longint find_m(const longint _p)
{
    return _p * _8_BIT;
}
longint _pow(longint m, longint e)
{
    if(e == 1)
        return m;
    if(e % 2 == 0)
        return ( _pow(m, e / 2) *  _pow(m, e / 2) ) % N;
    else
        return _pow(m, (e - 1) / 2) * _pow(m, (e + 1) / 2) % N;
}
longint RSA(const longint m)
{
    return _pow(m, e) % N;
}
