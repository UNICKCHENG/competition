/**
 * 1089 狼人杀-简单版(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/1038429385296453632
 * 解题思路:刚开始以为可以找到规律,最后仍然逃离不了暴力解决,i和j表示第i个和第j个为狼人
 *         然后一一判断,是否有且仅有两个说谎的人,同时他们一个是好人一个是狼人
 */
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
// zhicheng
// September,10,2018
int main() 
{
    freopen("1.in","r",stdin);
    int n,d[105];scanf("%d",&n); 
    for (int i = 1; i <= n; i++) scanf("%d",&d[i]);
    for (int i = 1; i <= n; i++) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            int re[105],cnt=0;
            vector<int> a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
                if (d[k] * a[d[k]<0?-d[k]:d[k]] < 0) re[cnt++] = k;
            if (cnt == 2 && a[re[0]] + a[re[1]] == 0) 
            {// 判断是否仅有两个说谎的人,并且一个是好人一个是狼人
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}