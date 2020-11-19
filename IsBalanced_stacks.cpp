#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> s;

    string str;
    cin>>str;
    int i;
    for(i=0;i<str.length();i++)
    {
        if(str[i]=='{'|| str[i]=='('|| str[i]=='[')
            {
                s.push(str[i]);
            }
        else if(str[i]==')')
        {
            if(s.top()=='(')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if(str[i]=='}')
        {
            if(s.top()=='{')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if(str[i]==']')
        {
            if(s.top()=='[')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
    }
    if(i==str.length() && s.empty())
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced";
    }
}
