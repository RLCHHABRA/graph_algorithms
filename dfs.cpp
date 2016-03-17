#include <bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int n;
int visited[1000];

void dfs(int source)
{
	visited[source] = 1;
	printf("%d \n",source);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		if(arr[source][i] == 1)
		{
			if(visited[i]==0)
				dfs(i);
		}
	}

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
		//arr[d-1][s-1] = 1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	dfs(0);
	return 0;
}
