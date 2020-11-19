#include "Stack.h"

 int main()
 {
     Stack<char> s;
     s.push('A');
     s.push('B');
     s.push('C');
     s.push('D');
     s.push('E');
//     Stack<int> s;
//
//     for(int i=0;i<=5;i++)
//     {
//         s.push(i);
//     }
     while(!s.isempty())
     {
         cout<<s.top()<<endl;
         s.pop();
     }
 }
