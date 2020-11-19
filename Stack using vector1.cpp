#include "Stack using vector1.h"

int main()
{
    Stack s;
   	 for(int i=0;i<=5;i++){
	 	s.push(i);
	 }

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
