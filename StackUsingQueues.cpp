#include<iostream>
#include<queue>
using namespace std;

class Stack
{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data)
    {
        if(q1.empty() && q2.empty())
        {
            q1.push(data);
        }
        else
        {
            if(q2.empty())
            {
                q1.push(data);
            }
            else
            {
                q2.push(data);
            }
        }
    }
    void pop()
    {
        if(q2.empty() && !q1.empty())
        {
            while(q1.size()>1)
            {
                int element=q1.front();
                q2.push(element);
                q1.pop();
            }
            q1.pop();
        }
        else if(q1.empty() && !q2.empty())
        {
            while(q2.size()>1)
            {
                int element=q2.front();
                q1.push(element);
                q2.pop();
            }
            q2.pop();
        }
    }
    int top()
    {
         if(q2.empty() && !q1.empty())
        {
            while(q1.size()>1)
            {
                int element=q1.front();
                q2.push(element);
                q1.pop();
            }
            int top_element=q1.front();
            q2.push(top_element);
            q1.pop();
            return top_element;
        }
        else if(q1.empty() && !q2.empty())
        {
            while(q2.size()>1)
            {
                int element=q2.front();
                q1.push(element);
                q2.pop();
            }
            int top_element=q2.front();
            q1.push(top_element);
            q2.pop();
            return top_element;
        }
    }
    bool empty()
    {
        return (q1.empty() && q2.empty());
//        if(q1.empty() && q2.empty())
//            return true;
//        else
//            return false;
    }
};

void Print(Stack s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    Stack s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    Print(s);
}
