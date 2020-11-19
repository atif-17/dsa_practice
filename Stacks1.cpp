#include "Stack1.h"

int main(){
	Stack<char> s;;

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');
	s.push('f');
//	 for(int i=0;i<=5;i++){
//	 	s.push(i);
//	 }
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}

//#include "Stack1.h"
//
//int main(){
//	Stack s;;
//
//	 for(int i=0;i<=5;i++){
//	 	s.push(i);
//	 }
//	while(!s.empty()){
//		cout<<s.top()<<endl;
//		s.pop();
//	}
//	return 0;
//}

