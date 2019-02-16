/**
 * 日志统计
 * 算法设计：尺选法
 * 以id为基准，利用数组ti[id]存放每个时间ts，给数组排序后，按照尺选法，判断是否可以在规定时间内满足k个赞
 * 注意：时间范围在[ts,ts+D)区间内，是左闭右开；id值也可能为 0。
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
// zhicheng
// February,16,2019
const int maxn=100005;
vector<int> ti[maxn];
vector<int> ans;
bool vis[maxn];
int pos[maxn];// 存储所有id的信息(不带重复的id)
int n,d,k;

bool judeg(int id)
{// 尺选法进行判断
    int len=ti[id].size();
    if(len<k) return false;// 该id不足k个赞
    sort(ti[id].begin(),ti[id].end());
    int r=0,l=0,sum=0;
    while(l<=r&&r<len)
    {// 尺选法
        ++sum;
        if(sum>=k)
        {
            if(ti[id][r]-ti[id][l]<d) return true;
            --sum;++l;
        }
        ++r;
    }
    return false;
}
int main()
{
    // freopen("日志统计/10.in","r",stdin);
    // freopen("日志统计/10.out","w",stdout);
    int ts,id,cnt=1;
    memset(vis,false,sizeof(vis));
    memset(pos,0,sizeof(pos));
    scanf("%d %d %d",&n,&d,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&ts,&id);
        if(!vis[id]){pos[cnt++]=id;vis[id]=true;}// 如果有新的id加入存入pos数组中
        ti[id].push_back(ts);
    }
    for(int i=1;i<cnt;++i)
    {// 遍历ti这个数组
        if(judeg(pos[i])) 
            ans.push_back(pos[i]);
    }
    sort(ans.begin(),ans.end());// 从小到大对id进行排序
    for(int i=0,len=ans.size();i<len;++i) printf("%d\n",ans[i]);// 输出结果
    return 0;
}