// OOPS
#include <iostream>
#include<cstring>
using namespace std;
// -------------- BLUE PRINT -------------------
class Pair{
public:
    int x;
    int y;

    Pair(int a, int b)
    {
        x=a;
        y=b;
    }
    bool operator >(Pair X)
    {

        if(x>X.x && y>X.y)
            return true;
        else
            return false;
    }
};
int main()
{
    Pair p2(10,20);
    Pair p1(15,40);
    if(p1>p2)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}
