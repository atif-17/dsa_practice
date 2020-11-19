#include "Stack using vector.h"

 int main()
 {
     cstack s;

     for(int i=0;i<=5;i++)
     {
         s.push(i);
     }

     while(!s.isempty())
     {
         cout<<s.top()<<endl;
         s.pop();
     }
 }

