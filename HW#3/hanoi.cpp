#include <iostream>
#include <string>
#include <stack>
using namespace std;

void r_hanoi(string, string, string, int);
void hanoi(int);

int main()
{
    //r_hanoi("left", "middle", "right", 3);
    cout << "*****************************\n";
    hanoi(3);
    return 0;
}
void r_hanoi(string from, string buffer, string to, int total)
{
    if(total == 1)
        cout << "Move disk " << total << " from " << from << " to " << to << endl;
    else
    {
        r_hanoi(from, to, buffer, total - 1);
        cout << "Move disk " << total << " from " << from << " to " << to << endl;
        r_hanoi(buffer, from, to, total - 1);
    }
}
void hanoi(int total)
{
    //if odd,move clockwise, else if even, move counter-clockwise
    stack< int > peg_A;
    stack< int > peg_B;
    stack< int > peg_C; 
    int disk = 0;
    int count = 0;
    for(int i = 1; i <= total; i++)
        peg_A.push(i);

    if(total % 2 == 1)
    {
        while(true)
        {
            //A<->C section
            if(peg_C.empty() || peg_A.top() < peg_C.top())
            {
                disk = peg_A.top();
                peg_A.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from A to C";
                peg_C.push(disk);
                count++;
            }
            else if(peg_A.empty() || peg_A.top() > peg_C.top())
            {
                disk = peg_C.top();
                peg_C.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from C to A";
                peg_A.push(disk);
                count++;                
            }
            //A<->B section
            if(peg_C.empty() || peg_A.top() < peg_B.top())
            {
                disk = peg_A.top();
                peg_A.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from A to B";
                peg_B.push(disk);
                count++;
            }
            else if(peg_A.empty() || peg_A.top() > peg_B.top())
            {
                disk = peg_B.top();
                peg_B.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from B to A";
                peg_A.push(disk);
                count++;                
            }
            //C<->B section
            if(peg_B.empty() || peg_C.top() < peg_B.top())
            {
                disk = peg_C.top();
                peg_C.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from C to B";
                peg_B.push(disk);
                count++;
            }
            else if(peg_C.empty() || peg_C.top() > peg_B.top())
            {
                disk = peg_B.top();
                peg_B.pop();
                cout << "Step " << count + 1 << ": move disk " << disk << " from B to C";
                peg_C.push(disk);
                count++;                
            }
        }
    }
    else
    {
        //A<->B section
        if(peg_C.empty() || peg_A.top() < peg_B.top())
        {
            disk = peg_A.top();
            peg_A.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from A to B";
            peg_B.push(disk);
            count++;
        }
        else if(peg_A.empty() || peg_A.top() > peg_B.top())
        {
            disk = peg_B.top();
            peg_B.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from B to A";
            peg_A.push(disk);
            count++;                
        }
        //A<->C section
        if(peg_C.empty() || peg_A.top() < peg_C.top())
        {
            disk = peg_A.top();
            peg_A.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from A to C";
            peg_C.push(disk);
            count++;
        }
        else if(peg_A.empty() || peg_A.top() > peg_C.top())
        {
            disk = peg_C.top();
            peg_C.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from C to A";
            peg_A.push(disk);
            count++;                
        }
        //B<->C section 
        if(peg_B.empty() || peg_C.top() < peg_B.top())
        {
            disk = peg_C.top();
            peg_C.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from C to B";
            peg_B.push(disk);
            count++;
        }
        else if(peg_C.empty() || peg_C.top() > peg_B.top())
        {
            disk = peg_B.top();
            peg_B.pop();
            cout << "Step " << count + 1 << ": move disk " << disk << " from B to C";
            peg_C.push(disk);
            count++;                
        }
    }
}
