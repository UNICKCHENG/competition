/**
 * 1020 Tree Traversals (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
 */
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
// zhicheng
//August 15,2018
const int maxn=31;
int in_order[maxn],post_order[maxn],rtree[maxn],ltree[maxn];
int n;

int build(int l1,int r1,int l2,int r2)
{//建树
	if(l1>r1) return 0;
	int node=post_order[r2];
	int p=l1;
	while(in_order[p]!=node) p++;
	ltree[node]=build(l1,p-1,l2,l2+p-l1-1);
	rtree[node]=build(p+1,r1,l2+p-l1,r2-1);
	return node;
}
void bfs(int root)
{//广度搜索进行层次遍历
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==root) printf("%d",u);
		else printf(" %d",u);
		if(ltree[u]) q.push(ltree[u]);
		if(rtree[u]) q.push(rtree[u]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&post_order[i]);
	for(int i=0;i<n;i++) scanf("%d",&in_order[i]);
	int root=build(0,n-1,0,n-1);
	bfs(root);
	printf("\n");
	return 0;
}

// --------------------------------------------------------
// the other code
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=31;
int in_order[maxn],post_order[maxn],level[100000]={0};
int n,best_id=0;

void build(int l1,int r1,int l2,int r2,int k)
{
	if(l1>r1) return;
	int node=post_order[r2];
	int p=l1;
	while(in_order[p]!=node) p++;
	level[k]=node;
	build(l1,p-1,l2,l2+p-l1-1,2*k+1);
	build(p+1,r1,l2+p-l1,r2-1,2*k+2);
	if(k>best_id) best_id=k;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&post_order[i]);
	for(int i=0;i<n;i++) scanf("%d",&in_order[i]);
	build(0,n-1,0,n-1,0);
	bool flg=false;
	for(int i=0;i<=best_id;i++)
		if(level[i])
		{
			if(flg==true) printf(" ");
			printf("%d",level[i]);
			flg=true;
		}
	printf("\n");
	return 0;
}
