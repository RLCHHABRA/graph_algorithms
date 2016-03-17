#include <bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int n;
int visited[1000];

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = 1;
	while(!q.empty())
	{
		int u = q.front();
		//printf("%d\n",u+1);
		q.pop();
	//	printf("Source %d\n",u+1);
		for(int i=0;i<n;i++)
		{
			
			if(arr[u][i]==1)
			{
				if(visited[i]==0)
				q.push(i);
				//printf("visited is  %d\n", i+1);
				visited[i] = 1;
			}
		}
		printf("%d \n",u);
	}
	printf("\n");
}

int main()
{
	
	scanf("%d",&n);
	int max_edges = n*(n+1);
	int i,j,k;
	for(i=0;i<max_edges;i++)
	{
		//printf("For quit press (-1,-1)\n");
		int s,d;
		
		scanf("%d%d",&s,&d);
		if(s==-1 && d==-1)
			break;
		arr[s][d] = 1;
	//	arr[d-1][s-1] = 1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	bfs(0);
	return 0;
}
