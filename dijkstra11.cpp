#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 1000000
int adj[MAX][MAX];
int done[MAX],pi[MAX],d[MAX],n;

int extract_min()
{
	int i,j,ans=-1;
	int min=INF;
	for(i=0;i<n;i++)
	{
		if(min>d[i] && done[i]!=0)
		{
			min = d[i];
			ans = i;
		}
	}
	return ans;
}
void dijksta(int s)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		pi[i]=-1;
		d[i]=INF;
		done[i]=-1;
	}
	d[s]=0;
	int traverse=0;
	while(traverse<n)
	{
		int u = extract_min();
		traverse++;
		done[u]=0;
		for(i=0;i<n;i++)
		{
			if(adj[u][i]!=0)
			{
				if(d[u]+adj[u][i]<=d[i])
				{
					d[i] = d[u]+adj[u][i];
				}
			}
		}
	}
}
int main()
{
	cin>>n;
	int i,j,k,max_edges = n*(n-1)/2;
	for(i=0;i<max_edges;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==-1 && b==-1)
		break;
		adj[a][b] = c;
		//adj[b][a] = c;
	}
	dijksta(0);
	for(i=0;i<n;i++)
	{
		printf("%d ",d[i]);
	}
}