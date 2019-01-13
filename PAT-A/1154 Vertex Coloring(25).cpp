/**
 * title: 1154 Vertex Coloring(25)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
 * 题目大意: 给定一个图节点信息（哪些节点相邻和给节点的颜色），判断是否每个相邻节点的颜色都不重复
 * 解题思路: 图的着色问题。因为本题时间限制给的比较宽，所以就暴力通过了。
 *          先把图给构建好（若要优化时间，可以边构建边判断），然后一一遍历每个结点，判断与其相邻节点的颜色是否一致，若一致则此次着色失败
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// zhicheng
// January,13,2018
vector<int> gra[10000];

int main()
{
    // freopen("1.in","r",stdin);
    int n,m,ver1,ver2,k;scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int min_ver,max_ver;
        scanf("%d %d",&ver1,&ver2);
        min_ver=min(ver1,ver2);max_ver=max(ver1,ver2);
        gra[min_ver].push_back(max_ver);
    }
    scanf("%d",&k);
    for(int v=0;v<k;v++)
    {
        vector<int> color(n);// 记载n个节点的颜色值
        map<int,bool> num_color;// 统计有多少种颜色出现
        int count=0;// 统计出现了多少种颜色
        bool flg=true;//判断它是否合格
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&color[i]);
            if(num_color[color[i]]==false) {num_color[color[i]]=true;count++;}
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0,len=gra[i].size();j<len;j++)
            {
                if(color[i]==color[gra[i][j]]) {flg=false;break;}
            }
            if(flg==false) break;
        }
        if(flg==true) printf("%d-coloring\n",count);
        else printf("No\n");
    }
    return 0;
}