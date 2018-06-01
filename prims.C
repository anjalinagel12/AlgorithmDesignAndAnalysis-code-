#include<stdio.h>
#include<stdlib.h>
int a,b,i,j,n,mincost=0,ne=1,min,sum;
int cost[100][100],visited[100];

int main()
{
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	printf("enter the matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}



	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	cout<<"edges are\n";
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]==0)
						continue;
					else
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		if(visited[a]==0 || visited[b]==0)
		{
			cout<<ne++<<"edges "<<a<<","<<b<<" is "<<\min;
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}


	cout<<"Min cost of spanning tree is "<<mincost;



}
