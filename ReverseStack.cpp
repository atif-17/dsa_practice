#include<iostream>
#include<stack>
using namespace std;
void PushBottom(stack<int> &s,int top_element)
{
    if(s.empty())
    {
        s.push(top_element);
        return;
    }

    int top=s.top();
    s.pop();
    PushBottom(s,top_element);
    s.push(top);
}
void reversestack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int top_element=s.top();
    s.pop();
    reversestack(s);
    PushBottom(s,top_element);
}
void print(stack<int> s)
{
    if(s.empty())
        return;

    cout<<s.top()<<" ";
    s.pop()
    print(s);
}
int main()
{
    stack<int> s;

    s.push(4);s.push(3);s.push(2);s.push(1);
    print(s);
    reversestack(s);
    print(s);
}

