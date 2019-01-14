/**
 * title: 1148 Werewolf - Simple Version(20)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624
 * 题目大意：给定N名玩家，已知其中共计两名狼人，并且有两个人再说谎（一个狼人和一名好人），现在需要指出两名狼人的序号，要求最小的一组结果
 * 解题思路：模拟。从狼人角度出发，大胆假设两名狼人对象，在这种情况下，再次查看这个N个人说的话是否满足题目，如果满足则表示假设成立
*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
// zhicheng
// January,14,2018
int main()
{
    int N;scanf("%d",&N);
    vector<int> a(N+1),w(N),b(N+1,1);;
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=N-1;i++)
    {// 从狼人角度出发，暴力求解
        for(int j=i+1;j<=N;j++)
        {
            int cnt=0;
            b[i]=b[j]=-1;
            for(int k=1;k<=N;k++)
                if(a[k]*b[a[k]<0?-a[k]:a[k]]<0) w[cnt++]=k;// 记录下说谎的人
            if(cnt==2&&b[w[0]]+b[w[1]]==0)
            {
                printf("%d %d\n",i,j);
                return 0;
            }
            b[i]=b[j]=1;
        }
    }
    printf("No Solution\n");
    return 0;
}