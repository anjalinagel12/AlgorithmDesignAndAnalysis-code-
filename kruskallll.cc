#include<stdio.h>
#include<iostream>
using namespace std;

int i,j,k,a,b,u,v,n,ne=1;
int minm,minmcost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main()
{
	cout<<"\n\tImplementation of Kruskal's algorithm\n";
	cout<<"\nEnter the no. of vertices:";
	cin>>n;
	cout<<"Enter the cost adjacency matrix:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	cout<<"The edges of Minimum Cost Spanning Tree are\n";
	while(ne < n)

		for(i=1,minm=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < minm)
				{
					minm=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
		    cout<<"edge("<<a<<","<<b<<") = "<<" minm";
			mincost +=minm;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"\n\tMinimum cost = \n"<<mincost;
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
