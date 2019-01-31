/**
 * 承压计算
 * 72665192664
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

double a[35][35];
const int diss=2086458231;
int main()
{
    freopen("1.in","r",stdin);
    double tmp;
    memset(a,0,sizeof(a));
    for(int i=1;i<30;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%lf",&tmp);
            a[i][j]=tmp+a[i-1][j-1]/2+a[i-1][j]/2;
        }
    }

    double maxn=-1,minn=9999999999;
    for(int i=1;i<=30;i++)
    {
        a[30][i]=a[29][i]/2+a[29][i-1]/2;
        if(maxn<a[30][i]) maxn=a[30][i];
        if(minn>a[30][i]) minn=a[30][i];
    }
    printf("%lf\n",(maxn/minn)*diss);
    return 0;
}