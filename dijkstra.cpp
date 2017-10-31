//it's single source sortest path algorithm.
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinty 9999
#define NIL -1

void creategraph();
void dijkstra(int s);
void findpath(int s,int v);
int n;
int adj[MAX][MAX];
int predecessor[MAX];
int pathlength[MAX];
int status[MAX];

int main()
{
	int s,v;
	creategraph();
	printf("Enter source vertex\n");
	scanf("%d",&s);
	dijkstra(s);
	while(1)
	{
		printf("Enter destination vertex(-1 to quit)\n");
		scanf("%d",&v);
		if(v==-1)
			break;
		if(v<0 || v>n)
			printf("This vertex does not exists\n");
		else if(v==s)
			printf("source and destination same\n");
		else if(pathlength[v]==infinty)
			printf("There is no path\n");
		else
			findpath(s,v);
	}
}
int min_temp()
{
	int i;
	int min = infinty;
	int k = NIL;
	for(i=0;i<n;i++)
	{
		if(status[i]==TEMP && pathlength[i]<min)
		{
			min = pathlength[i];
			k = i;
		}
	}
	return k;
}

void findpath(int s,int v)
{
	int i,u;
	int path[MAX];
	int shortdist = 0;
	int count = 0;
	while(v!=s)
	{
		count++;
		path[count] = v;
		u = predecessor[v];
		shortdist += adj[u][v];
		v = u;
	}
	count++;
	path[count] = s;
	printf("Shortest Path is:  ");
	for(i=count;i>=1;i--)
		printf("%d ",path[i]);
	printf("\nShortest distance is : %d\n",shortdist);
}
void creategraph()
{
	int i,max_edges,origin,destin,wt;
	printf("Enter no of vertices: \n");
	scanf("%d",&n);
	max_edges = n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(-1,-1 to quit)\n",i);
		scanf("%d%d",&origin,&destin);
		if(origin==-1 && destin==-1)
			break;
		printf("Enter weight for this edge\n");
		scanf("%d",&wt);
		if(origin>=n || destin>=n || origin<0 ||destin<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[origin][destin] = wt;
	}
}
void dijkstra(int s)
{
	int i,current;
	for(i=0;i<n;i++)
	{
		predecessor[i] = NIL;
		pathlength[i] = infinty;
		status[i] = TEMP;
	}
	pathlength[s] = 0;
	while(1)
	{
		current = min_temp();
		if(current==NIL)
			return;
		status[current] = PERM;
		for(i=0;i<n;i++)
		{
			if(adj[current][i]!=0 && status[i]==TEMP)
			{
				if(pathlength[current]+adj[current][i] < pathlength[i])
				{
					predecessor[i] = current;
					pathlength[i] = pathlength[current]+adj[current][i];
				}
			}
		}
	}
}
