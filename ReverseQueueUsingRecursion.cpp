#include<iostream>
#include<queue>
using namespace std;

void ReverseQueue(queue<int> &q)
{
    //base case
    if(q.empty())
    {
        return;
    }
    //recursive case
    int front_element=q.front();
    q.pop();
    ReverseQueue(q);
    q.push(front_element);
}
void Print(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int> q;
    q.push(1);q.push(2);q.push(3);q.push(4);q.push(5);
    Print(q);
    ReverseQueue(q);
    Print(q);
}
