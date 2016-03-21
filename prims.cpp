#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 10000000000000
typedef long long int lli;
typedef pair<int,lli> pii;
vector<pii> graph[MAX];

class comp
{
public:
	bool operator() (const pii& a,const pii& b)
	{
		return a.second>b.second;
	}
};

int main()
{
	int t,ll;
	scanf("%d",&t);
	for(ll=0;ll<t;ll++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			//graph[v].push_back(make_pair(u,w));
			graph[u].push_back(make_pair(v,w));
		}
		int s,d;
		scanf("%d%d",&s,&d);
		priority_queue<pii,vector<pii>,comp> pq;
		pq.push(make_pair(s,0));
		lli dist[n+1];
		for(int i=0;i<=n;i++)
		{
			dist[i] = INF;
		}
		dist[s] = 0;
		int *done = (int*)calloc(n+1,sizeof(int));
		int *prev = (int*)calloc(n+1,sizeof(int));
		while(!pq.empty())
		{
			int u = pq.top().first;
			pq.pop();
			for(int i=0;i<graph[u].size();i++)
			{
				int v = graph[u][i].first;
				lli w = graph[u][i].second;
				if(done[v]!=1 && dist[v]>dist[u]+w)
				{
					dist[v] = w;
					prev[v] = u;
					pq.push(make_pair(v,dist[v]));

				}
			}
			done[u] = 1;
		}
		if(dist[n]==INF)
			printf("NO\n");
		else
		{
			printf("%lld\n",dist[d]);
			/*vector<int> path;
			int i = n;
			while(prev[i]!=0)
			{
				path.push_back(i);
				i = prev[i];
			}
			path.push_back(1);
			for(i=path.size()-1;i>=0;i--)
				printf("%d ",path[i]);
			printf("\n");*/
		}
		for(i=0;i<10001;i++)
			graph[i].clear();
		free(done);
		free(prev);
	}
	
	return 0;
}