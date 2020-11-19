#include <iostream>
#include <string>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
string ThirdGreatest(string s[]) {

  // code goes here
  int n=sizeof(s)/sizeof(s[0]);

    for (int i=1 ;i<n; i++)
    {
        string temp = s[i];

        // Insert s[j] at its correct position
        int j = i - 1;
        while (j >= 0 && temp.length() > s[j].length())
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;
    }
return s[0];
}

int main(void) {

  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays. */

  string A[] = gets(stdin);
  cout << ThirdGreatest(A);
  return 0;

}
