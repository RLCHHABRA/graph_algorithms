#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
#define MAX 10

int adj[MAX][MAX];
int done[MAX];
int pi[MAX],key[MAX];
int n;

int extract_min()
{
	int min=INF,ans=-1;
	for(int i=0;i<n;i++)
	{
		if(key[i]!=-1 && min>key[i])
		{
			min = key[i];
			ans = i;
		}
	}
	return ans;
}

void mst_prim(int r)
{
	int i,j,k,ans=0;
	for(i=0;i<n;i++)
	{
		key[i]=INF;
		pi[i]=-1;
	}
	key[r]=0;
	int traverse=0,u;
	while(traverse<n)
	{
		u = extract_min();
		done[traverse]=u;
		ans+=key[u];
		key[u]=-1;
		traverse++;
		for(i=0;i<n;i++)
		{
			if(adj[u][i]!=0)
			{
				if(key[i]!=-1 && adj[u][i]<key[i])
				{
					pi[i] = u;
					key[i]=adj[u][i];
				}
			}
		}
	}
	printf("Total weight is %d\n",ans);
}

int main()
{
	scanf("%d",&n);
	int i,j,k;
	int max_edges = n*(n-1)/2;
	for(i=0;i<max_edges;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==-1&&b==-1)
			break;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	mst_prim(1);
	for(i=0;i<n;i++)
	{
		if(i<=n-2)
			printf("%d->",done[i]);
		else
			printf("%d\n",done[i]);
	}
	return 0;
}