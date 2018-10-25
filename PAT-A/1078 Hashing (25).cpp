/**
 * 1078 Hashing (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592
 * 题目大意：利用Quadratic probing进行插入，若无法插入哈希表中，则输出“-”
 * 解题思路：插入法和哈希。
 *          - https://en.wikipedia.org/wiki/Quadratic_probing
 */
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
// zhicheng
// October,25,2018
map<int,bool> cmp;

bool is_Prime(int n)
{
    if(n<=1) return false;
    for(int i=2;i<=n/i;i++) if(n%i==0) return false;
    return true;
}
void _insert(int key,int size)
{
    int index;
    for(int i=0;i<size;i++)
    {
        index=(key+i*i)%size;
        if(!cmp[index])
        {
            cmp[index]=true;
            printf("%d",index);
            return;
        }
    }
    printf("-");
}
int main()
{  
    int m,n,tmp;
    scanf("%d %d",&m,&n);
    while(!is_Prime(m)) m++;
    for(int i=0;i<n;i++)
    {
        if(i!=0) printf(" ");
        scanf("%d",&tmp);tmp%=m;
        _insert(tmp,m);
    }
    printf("\n");
    return 0;
}