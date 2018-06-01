#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define n 8
void printSolution(int board[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int board[n][n],int row,int col)
{
    int i,j;

    for(i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return false;
    for(i=row,j=col;i<n&&j>=0;i++,j--)
        if(board[i][j])
            return false;
    return true;
}

bool solveNQutil(int board[n][n],int col)
{
    int i,j;

    if(col>=n)
        return true;
    for(i=0;i<n;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;


            if(solveNQutil(board,col+1))
            {
                return true;
            }
            board[i][col]=0;
        }

    }
    return false;
}
bool solveNQ()
{
    int i,j;

    int board[n][n]={0};
    if(solveNQutil(board,0)==false)
     {


        cout<<"Solution not possible";
        return false;
     }
    else
    {
        printSolution(board);
        return true;
    }
}
int main()
{
    //cout << "Enter n :" ;
    //cin>>n;
    solveNQ();
    return 0;
}
