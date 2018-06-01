#include<stdio.h>
#include<iostream>
using namespace std;
int a,b,u,v,n,i,j,minm,mincost=0,ne=1;
int visited[100],cost[100][100];

int main()
{
	cout<<"Enter no. of edged : ";
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
        for(i=1,minm=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<minm)
                {
                    minm=cost[i][j];
                    a=u=i;
                    b=v=j;

                }
            }
        }
        while(visited[u])
            u=visited[u];
         while(visited[v])
            v=visited[v];
        if(u!=v)
        {
            cout<<endl<<ne++<<" "<<a<<","<<b<<"="<<minm<<endl;
            visited[v]=u;
            mincost+=minm;
        }
        cost[a][b]=cost[b][a]=999;

    }
	cout<<"min cost of spanning tree is "<<mincost;
}


