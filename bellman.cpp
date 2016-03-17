#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 1000000
int adj[MAX][MAX];
int done[MAX];
int d[MAX],n;

void bellman(int s)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		d[i]=INF;
		done[i]=-1;
	}
	d[s]=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(adj[j][k]!=0)
				{
					if(d[j]+adj[j][k]<=d[k])
					{
						d[k] = d[j]+adj[j][k];
					}
				}
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
	bellman(0);
	for(i=0;i<n;i++)
	{
		printf("%d ",d[i]);
	}
}