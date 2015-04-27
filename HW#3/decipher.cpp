#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#define N 4146153463
#define e 3
#define d 2764016427
#define _8_BIT 256

unsigned long find_m(const int, const int); //function overloading
unsigned long find_m(const int);
unsigned long _pow(const unsigned long, unsigned long);

unsigned long RSA(const unsigned long); 

using namespace std;
int main()
{
    //printf("%d", sizeof(unsigned long long int));
    ifstream ifs;
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
unsigned long find_m(const int _p, const int q)
{
    return _p * _8_BIT + q;
}
unsigned long find_m(const int _p)
{
    return _p * _8_BIT;
}
unsigned long _pow(const unsigned long m, unsigned long k)
{
    unsigned long total = 1;
    unsigned long i = 1;
    while(i <= k)
    {
        total *= m;
        i++;
    }
    return total;
}
unsigned long RSA(const unsigned long m)
{
    return _pow(m, e) % N;
}
