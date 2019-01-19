#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

map<int,int> m;
int main()
{
    // freopen("1.in","r",stdin);
    int n,tmp;
    while(scanf("%d",&n)!=EOF)
    {
        int best=0,maxn=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            m[tmp]++;
            if(m[tmp]>maxn){best=tmp;maxn=m[tmp];}// 更新最高频率元素值，和出现的次数
            else if(m[tmp]==maxn&&tmp<best){best=tmp;}// 如果出现的次数和最高频率元素出现的次数一致，则将最小的值更新为最高频率元素
        }
        printf("%d\n",best);
        m.clear();
    }
    return 0;
}