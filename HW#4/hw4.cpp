#include <iostream>
#include <fstream>
#include <string>
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

double shortest_path(string &);
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
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m + 1; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << "AA"<< endl;
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m; j++)
            cout << h[i][j] << " ";
        cout << endl;
    }*/
    string movement;
    cout << shortest_path(movement) << endl;
    cout << movement << endl;

    release();
    return 0;
}
double shortest_path(string& str)
{
}
