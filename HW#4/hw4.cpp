#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <ctime>

using namespace std;

/************************************
  Note that in general using global
  variables is a bad habit.
  I use globals here because I don't 
  want to scare you with "double***"
 *************************************/

int m;
int n;
double **v;  // n*(m+1) 2D-array
double **h;  // (n+1)*m 2D-array

// For internal use only. Do not really use them directly
double *real_v;
double *real_h;

double shortest_path(int, int);
void print(int , int);
void readParameters()
{
    ifstream ifs("input3", ifstream::binary);

    ifs.read((char*)&m, sizeof(int));
    ifs.read((char*)&n, sizeof(int));

    real_v = new double[n*(m+1)];
    real_h = new double[(n+1)*m];

    ifs.read((char*)real_v, sizeof(double)*n*(m+1));
    ifs.read((char*)real_h, sizeof(double)*(n+1)*m);

    v = new double*[n];
    for (int i=0; i<n; ++i)
        v[i] = &(real_v[i*(m+1)]);

    h = new double*[n+1];
    for (int i=0; i<n+1; ++i)
        h[i] = &(real_h[i*m]);

    ifs.close();
}

void release()
{

    delete []v;
    delete []h;

    delete []real_v;
    delete []real_h;
}
int main()
{
    readParameters();
    cout << shortest_path(n, m) << endl;
    print(n, m);
    release();
    return 0;
}
double distance_visted[ 1000 ][ 1000 ];
bool visited[ 1000 ][ 1000 ];
char arr[ 1000 ][ 1000 ];

double shortest_path( int n , int m ){

    if( n == 0 && m == 0 ) return 0;
    if( visited[ n ][ m ] ) return distance_visited[ n ][ m ];
    double tmph = 10000000;
    double tmpv = 10000000;
    if( m > 0 )
        tmph = h[ n ][ m - 1 ] + shortest_path( n , m - 1 );
    if( n > 0 )
        tmpv = v[ n - 1 ][ m ] + shortest_path( n - 1 , m );
    if(tmph < tmpv)
        arr[n][m] = 'h';
    else
        arr[n][m] = 'v';
    visited[ n ][ m ] = true;
    double distance = min(tmph, tmpv);
    distance_visited[ n ][ m ] = distance;
    return distance;
}
void print(int n, int m)
{
    stack <char> str;
    while(n != 0 || m != 0)
    {
        str.push(arr[n][m]);
        if (str.top() == 'v')
            n--;
        else
            m--;
    }
    while(!str.empty())
    {
        cout << str.top();
        str.pop();
    }
    cout << endl;
}

