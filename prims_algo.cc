#include<stdio.h>
#include<iostream>
using namespace std;
int a,b,i,j,n,mincost=0,ne=1,minm;
int cost[100][100],visited[100];

int main()
{
	cout<<"Enter n";
	cin>>n;
	cout<<"Enter cost matrix";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
            cin>>cost[i][j];
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
        for(i=1,minm=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<minm)
                {
                    if(visited[i]!=0){
                    minm=cost[i][j];
                    a=i;
                    b=j;
                    }
                }
            }
        }
        if(visited[a]==0||visited[b]==0)
        {
            cout<<endl<<ne++<<" "<<a<<","<<b<<"="<<minm<<endl;
            visited[b]=1;
            mincost+=minm;
        }
        cost[a][b]=cost[b][a]=999;
    }

	cout<<"Min cost of spanning tree is "<<mincost;



}
