#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;
#define lu_MAX   4294967295 //2^64
#define int_MAX  2147483647 //2^32

unsigned long string2Int(const string&);
unsigned long RSA(unsigned long, unsigned long); 

unsigned long N = 0;
unsigned long d = 0;
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
        ofs << RSA(string2Int(s), d) << endl;
    
    ifs.close();
    ofs.close();
    return 0;
}
unsigned long string2Int(const string& str)
{
    unsigned long num = 0;
    for (unsigned long i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            num *= 10;
            num += int(str[i] - '0');
        }
    }
    return num;
} 
//s^d = m (mol N)
unsigned long RSA(unsigned long s, unsigned long d)
{
    if(d == 1)
        return s;
    if(d % 2 == 0)
        return ( RSA(s, d / 2) *  RSA(s, d / 2) ) % N;
    else
        return RSA(s, (d - 1) / 2) * RSA(s, (d + 1) / 2) % N;
}
