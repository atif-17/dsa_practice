#include <iostream>
#include<cstring>
#include<stack>
using namespace std;
bool RedundantParanthesis(stack<char> s, string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='['||str[i]=='{'||str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
        {
            s.push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']')
        {
            if(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/'||s.top()=='%')
            {
                while(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/'||s.top()=='%')
                {
                    s.pop();
                }
                s.pop();  //popping out the opening bracket also
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}
int main() {
    stack<char> s;
    string str;
    getline(cin,str);
    RedundantParanthesis(s,str)?cout<<"Redundant Brackets Present":cout<<"Redundant Brackets Absent";
}

