#include<iostream>
using namespace std;

bool IsSafeToPut(int board[][10], int n, int i, int j)
{
    for(int k=0;k<n;k++)
    {
        if(board[i][k]==1 || board[k][j]==1)
        {
            return false;
        }
    }
    //check left diagonal
    int r=i;
    int c=j;
    while(r>=0 && c>=0)
    {
        if(board[r][c]==1)
            return false;
        r--;
        c--;
    }
    //check right diagonal
    r=i;
    c=j;
    while(r>=0 && c<n)
    {
        if(board[r][c]==1)
            return false;
        r--;
        c++;
    }

    return true;
}
bool NQueen(int board[][10], int n, int i)
{
    //base case
    if(i==n)
    {
        //Print the solution
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                cout<<board[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //recursive case
    for(int j=0;j<n;j++)
    {
        if(IsSafeToPut(board,n,i,j)==true)
        {
            board[i][j]=1;   //Place the Queen
            bool KyaBaakiBaatBani=NQueen(board,n,i+1);
            if(KyaBaakiBaatBani==true)
            {
                return true;
            }
            board[i][j]=0;   //if(KyaBaakiBaatBani==false)
        }
    }

    return false;
}
int main(){
    int board[10][10]={0};
    int n;
    cin>>n;
    NQueen(board,n,0);
    return 0;
}
