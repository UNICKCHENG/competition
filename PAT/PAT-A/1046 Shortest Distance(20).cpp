/**
 * 1046 Shortest Distance（20 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424
 * 题目大意:给出一个环形图,求图上任意两个节点的最短路径值
 * 解题思路:因为一个节点接着一个节点,且只有一个闭合回路,所以及其简单.
 *        首先,求出各节点到节点1的距离和节点1到节点N的距离(1-2-3-4-..-N)
 *        其次,求节点i到节点j的距离(i<j),有两条路线,一是i~(i+1)~...~(j-1)~j;二是i~(i-1)~1~N~N-1~..~(j+1)~j
 *        比较二者,并输出最短距离
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 26,2018
const int maxn=100000+5;
int a[maxn];

int main()
{
    // freopen("1.in","r",stdin);
    int n,m,tmp;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i==n) {scanf("%d",&tmp);break;}
        scanf("%d",&a[i+1]);
        a[i+1]+=a[i];
    }
    int p,q;
    for(scanf("%d",&m);m;m--)
    {
        scanf("%d %d",&p,&q);
        if(p==q){printf("0\n");continue;}
        int minn=p>q?q:p;
        int maxx=p>q?p:q;
        printf("%d\n",(a[maxx]-a[minn])<(a[minn]+a[n]-a[maxx]+tmp)?(a[maxx]-a[minn]):(a[minn]+a[n]-a[maxx]+tmp));
    }
    return 0;
}
