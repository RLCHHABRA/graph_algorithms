#include <bits/stdc++.h>
using namespace std;

#define NIL -1
#define MAX 500
int n;
class edge
{
public:
	int u,v,wt;
	edge* next;
};
edge *front=NULL;
edge tree[MAX];
void make_tree()
{
	edge* temp;
	int v1,v2,root_v1,root_v2;
	int father[MAX];
	for(int i=0;i<MAX;i++)
		father[i]=NIL;
	int i,count=0;
	while(front!=NULL && count<n-1)
	{
		edge *temp2 = front;
		front=front->next;
		temp = temp2;
		v1 = temp->u;
		v2 = temp->v;
		while(v1!=-1)
		{
			root_v1 = v1;
			v1 = father[v1];
		}
		while(v2!=-1)
		{
			root_v2 = v2;
			v2 = father[v2];
		}
		if(root_v1!=root_v2)
		{
			count++;
			tree[count].u = temp->u;
			tree[count].v = temp->v;
			tree[count].wt = temp->wt;
			father[root_v2] = root_v1;
		}
	}
	if(count<n-1)
	{
		printf("No spanning tree\n");
		exit(1);
	}
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	int max_edges = n*(n-1)/2;
	for(i=0;i<max_edges;i++)
	{
		int a,b,wt;
		scanf("%d%d%d",&a,&b,&wt);
		if(a==-1 && b==-1 && wt==-1)
		{
			break;
		}	
		else
		{
			
			edge *temp = new edge;
			temp->u = a;
			temp->v = b;
			temp->wt = wt;

			if(front==NULL || temp->wt<front->wt)
			{
				temp->next = front;
				front = temp;
			}
			else
			{

				edge* q = front;
				while(q->next!=NULL && q->next->wt<=temp->wt)
					q = q->next;
				temp->next = q->next;
				q->next = temp;
				if(q->next==NULL)
					temp->next = NULL;
			}
		}
	}

	make_tree();
	int weight = 0;
	for(i=1;i<n;i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		weight += tree[i].wt;
	}
	printf("Minimum spanning tree weight %d\n",weight);
	return 0;
}