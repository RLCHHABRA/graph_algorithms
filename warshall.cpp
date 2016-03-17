#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF 1000000
int adj[MAX][MAX],n;
int dist[MAX][MAX];
void warshall()
{
	int i,j,k;
	for(k=0;k<n;k++)
		{
		for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int main()
{
	cin>>n;
	int i,j,k,max_edges = n*(n-1);
	for(i=0;i<max_edges;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==-1 && b==-1)
		break;
		adj[a][b] = c;
		//adj[b][a] = c;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				dist[i][j] = 0;
			else if(adj[i][j]==0)
				dist[i][j]=INF;
			else
				dist[i][j]=adj[i][j];
		}
	}
	warshall();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dist[i][j]==INF)
				printf("I ");
			else
				printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
}