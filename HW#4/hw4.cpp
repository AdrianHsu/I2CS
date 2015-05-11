#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
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

class Node
{
public:
    Node(int _x, int _y)
        :x(_x), y(_y){};

    int x;
    int y;
};


double shortest_path(int, int);
void print(int , int);
double Dijkstra();
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
    cout << endl;
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m; j++)
            cout << h[i][j] << " ";
        cout << endl;
    }*/
    cout << shortest_path(n, m) << endl;
    print(n, m);
    cout << Dijkstra() << endl;
    release();
    return 0;
}
double distance_visited[ 1000 ][ 1000 ];
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
        arr[ n ][ m ] = 'h';
    else
        arr[ n ][ m ] = 'v';
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
        str.push(arr[ n ][ m ]);
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
const int dx[4] = {0, 1,0, -1};
const int dy[4] = {1, 0, -1,0};

//Node parent[1000][1000];
bool D_visit[1000][1000]; 
double d[1000][1000];
bool operator<(const Node& n1, const Node& n2)
{
    return d[ n1.y ][ n1.x ] > d[ n2.y ][ n2.x ];
}
double Dijkstra()
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            d[ i ][ j ] = 10000000;
    priority_queue< Node >PQ;

    Node p(0, 0);
    d[p.y][p.x] = 0;
    //parent[p.y][p.x] = p;
    PQ.push(p);
    while(true)
    {
        Node a(-1, -1);
        while (!PQ.empty())
        {
            Node _top = PQ.top();
            PQ.pop();
            a = _top;
            if(!D_visit[_top.y][_top.x])
            {
                break;
            }
        }
        if (a.x == -1 || a.y == -1) break;
        D_visit[a.y][a.x] = true;
 
        for(int i = 0; i < 4; i++)
        {
            int newx = a.x + dx[i];
            int newy = a.y + dy[i];
            if (newx < 0 || newx > m || newy < 0 || newy > n) continue;
            double tmp = 0;
            switch(i)
            {   
                case 0: 
                    tmp = v[a.y][a.x];
                    break;
                case 1: 
                    tmp = h[a.y][a.x];
                    break;
                case 2:
                    tmp = v[a.y - 1][a.x];
                    break;
                case 3:
                    tmp = h[a.y][a.x - 1];
                    break;
            }
            if(!D_visit[newy][newx])
            {
                if(d[a.y][a.x] + tmp < d[newy][newx])
                {
                    d[newy][newx] = d[a.y][a.x] + tmp;
                    //parent[newy][newx] = a;
                    PQ.push(Node(newx, newy));
                }
            }
        }        
    }
    return d[n][m];
}
