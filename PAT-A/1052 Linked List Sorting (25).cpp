/**
 * 1052 Linked List Sorting (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464
 * 题目大意:将一段链表按数据值从小到大排序重新得到一个新的链表,并输出该链表的各个节点
 * 解题思路:链表入门级题目.首先将零散的节点信息通过数组存好,这样可以从头节点往后遍历至结尾,其次排序,输出即可.
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// Augsut 27,2018
const int maxn=100000+5;
const int maxx=1000000;
typedef struct{int add;int key;}D;D d[maxn];
int add[maxx],nex[maxx],flg[maxx];
bool comp(D a,D b){return a.key<b.key;}
int main()
{
    // freopen("1.in","r",stdin);
    int N,node,n=0,Address,Key,Next;
    for(scanf("%d %d",&N,&node);N;N--)
    {
        scanf("%d %d %d",&Address,&Key,&Next);
        add[Address]=Key;
        nex[Address]=Next;
        flg[Address]=1;
    }
    if(node==-1||flg[node]==0) {printf("%d ",n);node==-1?printf("-1\n"):printf("%05d\n",node);return 0;}
    for(int i=node;i!=-1;i=nex[i])
    {
        d[n].add=i;
        d[n].key=add[i];
        n++;
    }
    sort(d,d+n,comp);printf("%d %05d\n",n,d[0].add);
    for(int i=0;i<n;i++) 
    {
        printf("%05d %d ",d[i].add,d[i].key);
        if(i==n-1)printf("-1\n");
        else printf("%05d\n",d[i+1].add);
    }
    return 0;
}
