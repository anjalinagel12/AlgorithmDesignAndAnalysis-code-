#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,n,i,j,min,mincost=0,ne=1;
int parent[100],cost[100][100];
int sum;
int find(int);
int uni(int,int);

int main()
{
	cout<<"Enter no. of vertices: ";
	cin>>n;
    cout<<"\nEnter the matrix";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
            cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}


	cout<<"minimum spanning tree edges are\n";
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u])
            u=parent[u];
        while(parent[v])
            v=parent[v];
        if(u!=v)
		{
			cout<<ne<<" edge is "<<a<<","<<b<<"->"<<min;
			ne++;
			parent[v]=u;
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"min cost of spanning tree is "<<mincost;
}


