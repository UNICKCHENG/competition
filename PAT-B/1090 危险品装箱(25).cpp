/**
 * 1090 危险品装箱(25)
 * https://pintia.cn/problem-sets/994805260223102976/problems/1038429484026175488
 * 接替思路:竟然未像往届一样的套路,不过仍然逃离不了map
 *         - 首先,分类存好,比如10001下不可与之共存的物品编号,用ma[10001][]一一存放好
 *         - 在判断是否可以安全运输的时候,同时记录每件物品下不可与之共存的物品编号,后面一旦出现则不可安全输出
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
// zhicheng
// September,10,2018
map<int ,vector<int> > ma;

int main()
{
    freopen("1.in","r",stdin);
    int n,m,a,b;
    for(scanf("%d %d",&n,&m);n;n--)
    {
        scanf("%d %d",&a,&b);
        ma[a].push_back(b);
        ma[b].push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        bool d[100000]={false};
        int k,tmp;bool flg=true;
        for(scanf("%d",&k);k;k--)
        {
            scanf("%d",&tmp);
            if(flg==false) continue;
            if(d[tmp]==true) {flg=false;continue;}
            for(int i=0;i<ma[tmp].size();i++)d[ma[tmp][i]]=true;
        }
        flg==false? printf("No\n"):printf("Yes\n");
    }
    return 0;
}