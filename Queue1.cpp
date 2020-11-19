#include "Queue1.h"

int main()
{
    Queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');
    q.push('f');
//    for(int i=0;i<=5;i++)
//    {
//        q.push(i);
//    }
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}
