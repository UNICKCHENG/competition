/**
 * 1084 外观数列(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805260583813120
 * 解题思路:原本打算寻找各项规律,发现只有依据题意的规律一项一项的求解
 *         遍历第n项,按题意的规律将结果存入另一个数组中
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,4,2018
int a[100000],b[100000],cn;
int fun(int p[],int* q ,int l)
{
    int cnt=0;
    for(int i=0,j;i<l;i=j)
    {
        q[cnt++]=p[i];
        j=i;
        while(j<l&&p[i]==p[j]) j++;
        q[cnt++]=j-i;
    }
    return cnt;
}
int main()
{
    int n,d,len;
    scanf("%d %d",&d,&n);
    a[0]=d;len=1;
    for(int i=1;i<n;i++)
    {
        if(i%2) len=fun(a,b,len);
        else len=fun(b,a,len);
    }
    if(n%2) for(int i=0;i<len;i++) printf("%d",a[i]);
    else for(int i=0;i<len;i++) printf("%d",b[i]);
    printf("\n");
}