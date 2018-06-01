#include<iostream>
#include<stdlib.h>
using namespace std;
int min(int b,int c)
{
	int min;
	if(b>c)
		min=c;
	else
		min=b;
	return min;
}
void floyd(int a[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
int main()
{
	int n,i,j,a[10][10];
	cout<<"Enter no of vertices :\n";
	cin>>n;
	cout<<"Enter the weighted adjacency matrix and if no edge is present enter -1\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==-1)
				a[i][j]=999;
		}
	floyd(a,n);
	cout<<"All pair shortest path of given graph is:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j];
			cout<<"\t";
		}
	cout<<"\n";
	}
	return 0;
}
