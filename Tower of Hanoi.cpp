#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char helper, char destination)
{
    //base case
    if(n==0)
        return;

    //recursive case
    TowerOfHanoi(n-1,source,destination,helper);
    cout<<"Shift disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    TowerOfHanoi(n-1,helper,source,destination);
}
int main()
{
    int n;
    cin>>n;
    TowerOfHanoi(n,'A','B','C');
}
