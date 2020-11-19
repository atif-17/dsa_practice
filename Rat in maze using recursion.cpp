#include<iostream>
using namespace std;

bool RatInMaze(char maze[][5],int m,int n,int sol[][10],int i,int j)
{
    //base case
    if(i==m-1 && j==n-1)
    {
        sol[i][j]=1;
        //Print solution
        for(int k=0;k<m;k++)
        {
            for(int l=0;l<n;l++)
            {
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;     //return false to
    }
    //recursive case
    sol[i][j]=1;
    //Chech Rightwards
   if(j+1<n && maze[i][j+1]!='X')
   {
       bool KyaRightSeMazeSolveHoRahaHai=RatInMaze(maze,m,n,sol,i,j+1);
       if(KyaRightSeMazeSolveHoRahaHai)
       {
           return true;
       }
   }
   //Check Downwards
   if(i+1<m && maze[i+1][j]!='X')
   {
       bool KyaNeecheSeMazeSolveHoRahaHai=RatInMaze(maze,m,n,sol,i+1,j);
       if(KyaNeecheSeMazeSolveHoRahaHai)
       {
           return true;
       }
   }
   sol[i][j]=0;
   return false;
}
int main(){
    char maze[][5]={
        "0000",
        "00XX",
        "0000",
        "XX00"
    };
    int sol[10][10]={0};
    RatInMaze(maze,4,4,sol,0,0);
    return 0;
}
