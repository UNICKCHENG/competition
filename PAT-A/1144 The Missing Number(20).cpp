/**
 * title: 1144 The Missing Number(20)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
 * 题目大意: 给定n个数的序列，查找消失掉的正整数。
 * 解题思路: 水题+映射。无厘头的题目。读完题意根本不知道题目在讲什么，琢磨半天，才知道从1到正无穷开始逐个遍历，一旦发现哪个数字序列中没有出现，则将该数字定义为消失的数字
*/
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
// zhicheng
// January,18,2019
int main()
{
    int n,tmp,num=0;
    map<int,bool> m;
    for(scanf("%d",&n);n;n--)
    {
        scanf("%d",&tmp);
        m[tmp]=true;
    }
    while(++num)
        if(m[num]==false) break;
    printf("%d\n",num);
    return 0;
}