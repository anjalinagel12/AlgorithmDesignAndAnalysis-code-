#include<iostream>
#include<stdlib.h>
using namespace std;
int max(int a,int b)
{
   return((a)>(b))?(a):(b);
}

void knapsack(int n,int w[],int p[],int m)
{
   int v[10][10],j,i;
   for(i=0;i<=n;i++)
   {
      for(j=0;j<=m;j++)
      {
         if(i==0||j==0)
            v[i][j]=0;
         else if(j<w[i])
            v[i][j]=v[i-1][j];
         else
            v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
      }
   }
   for(i=0;i<=n;i++)
   {
      for(j=0;j<=m;j++)
         cout<<v[i][j]<<"\t";

         cout<<"\n";
  }
  cout<<"the optimized value is\n"<<v[n][m]<<"\n";

}

int main()
{
   int w[10],p[10],m,n,i;
   cout<<"enter number of items\n";
   cin>>n;
   cout<<"enter the weights\n";
   for(i=1;i<=n;i++)
       cin>>w[i];
   cout<<"enter the profits\n";
   for(i=1;i<=n;i++)
     cin>>p[i];
   cout<<"enter the size of knapsack\n";
   cin>>m;
   knapsack(n,w,p,m);
   return 0;
}








0 3 0 0 6 5
3 0 1 0 0 4
0 1 0 6 0 4
0 0 6 0 8 5
6 0 0 8 0 2
5 4 4 5 2 0
