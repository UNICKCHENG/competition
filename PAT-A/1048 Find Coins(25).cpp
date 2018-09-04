/**
 * 1048 Find Coins（25 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840
 * 题目大意:给出一串数字,查找是否存在任意两个数字之和为M,如果有多个,输出最小数最小的一组
 * 解题思路:输入一个数字a,则在后面只要出现值M-a的数字,则这样的两个数字便满足题意
 *         相似题目:[PAT-A-1044]https://github.com/UNICKCHENG/competition/blob/master/PAT/PAT-A/1044%20Shopping%20in%20Mars(25).cpp
 */
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
// zhicheng
// Augsut 26,2018
int v1=510,v2;//每个数字不超过500
map<int,bool> a;
int main()
{
    // freopen("1.in","r",stdin);
    int n,m,num;
    for(scanf("%d %d",&n,&m);n;n--)
    {
        scanf("%d",&num);
        if(num>=m)continue;
        if(a[num]==true)
        {
            int minn=num<m-num?num:m-num;
            if(v1>minn) {v1=minn;v2=m-minn;}
            a[num]=false;
        }
        else a[m-num]=true;// 标记后面需要找m-num数,便可组成满足题意的一对数
    }
    if(v1==510) printf("No Solution\n");
    else printf("%d %d\n",v1,v2);
    return 0;
}
