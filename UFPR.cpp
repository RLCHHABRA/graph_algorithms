#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int sum;
};
node *tree;
int *arr;

void buildTree(int a,int b,int index)
{
	if(a==b)
	{
		tree[index].sum = arr[a];
		return;
	}
	int mid = (a+b)/2;
	buildTree(a,mid,index*2);
	buildTree(mid+1,b,index*2+1);
	tree[index].sum = tree[index*2].sum + tree[index*2+1].sum;

}

node* query(int al,int ar,int index,int ql,int qr)
{
	if(ql>ar || qr<al)
	{
		node* ans = (node*)calloc(1,sizeof(node));
		ans->sum = 0;
		return ans;
	}
	if(ql<=al && qr>=ar)
	{
		return &tree[index];
	}
	int mid=(al+ar)/2;
	node* q1 = query(al,mid,index*2,ql,qr);
	node* q2 = query(mid+1,ar,index*2+1,ql,qr);
	node *ans = (node*)calloc(1,sizeof(node));
	ans->sum = q1->sum+q2->sum;
	return ans;

}

int main()
{
	int n;
	scanf("%d",&n);
	arr = (int*)calloc(n+10,sizeof(int));
	tree = (node*)calloc(n*4,sizeof(node));
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	buildTree(0,n-1,1);
	int q;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		int id,ql,qr;
		scanf("%d%d",&ql,&qr);
		ql--;
		qr--;
		node* ans = query(0,n-1,1,ql,qr);
		printf("%d\n",ans->sum);
	}
	return 0;
}