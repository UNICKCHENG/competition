/**
 * 1045 Favorite Color Stripe（30 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456
 * 题目大意:给定彩色条纹的颜色种类数目,和喜爱的颜色,以及给定一条彩色条纹带,每一段对应一种颜色(长度为l),
 *        现在要在满足所选颜色皆为自己所喜爱的情况下,得到一条长度最长的彩色条纹带(不需要的部分将被裁剪掉,其余部分将按原本位置先后进行缝合)
 * 解题思路:(新手如坑,90分钟手算推演,20分钟完成程序)哈系散列+前序列和(我也不太清楚叫啥,暂且叫他前序列和),
 *         做此题时,首先想到乙级中"有几个PAT"的那一题(https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616)
 *         因为不需要求出最长长度的搭配结果,只需要输出最长长度即可,所以用到前序列和最为方便
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 25,2018
const int maxn=200+5;
int a[maxn]={0},t[maxn]={0};

int main()
{
    // freopen("1.in","r",stdin);
    int n,m,l,tmp,ans=0;
    scanf("%d\n%d",&n,&m);
    for(int i=1;i<=m;i++){scanf("%d",&tmp);t[tmp]=i;}
    for(scanf("%d",&l);l;l--)
    {
        scanf("%d",&tmp);
        if(t[tmp]==0)continue;
        int cnt=t[tmp];
        while(cnt-1!=0&&a[cnt-1]==0) cnt--;
        while(cnt<=t[tmp]-1) {a[cnt]=a[cnt-1];cnt++;}
        a[cnt]=((a[cnt-1]+1)>(a[cnt]+1))?(a[cnt-1]+1):(a[cnt]+1);
        if(ans<a[cnt]) ans=a[cnt];
    }
    printf("%d\n",ans);
}
