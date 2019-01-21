/**
 * title: 1005 继续(3n+1)猜想(25)
 * links: https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// zhicheng
// January,21,2019
bool vis[101];
inline void fun(int n)
{// 3n+1法则
    int t=n;
    while(n>100||vis[n]==false)
    {
        if(n<=100&&n!=t) vis[n]=true;// 统计n在进行3n+1转换的时候都产生了那些数
        if(n%2) n=3*n+1;
        n/=2;
    }
}
int main()
{
    int n,a[100],cn=0;
    bool first=true;
    memset(vis,false,sizeof(vis));
    scanf("%d",&n);
    vis[1]=true;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        fun(a[i]);// a[i]作为一个整数，进行3n+1转换时候产生了哪些数字，统计好这些数字
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++)
    {// 判断a[i]是否作为3n+1转换时出现过，记录那些没有出现过的数
        if(vis[a[i]]==false)
        {
            if(first==false) printf(" ");
            else first=false;
            printf("%d",a[i]);
        }
    }
    printf("\n");
    return 0;
}