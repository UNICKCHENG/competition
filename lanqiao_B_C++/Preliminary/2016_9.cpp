/**
 * 交换瓶子
 * 解题思路：贪心，O(n)
 * 因为瓶子的编号是1~N，如果现在的瓶子根据编号不在对应的位置,则找到属于该位置的瓶子进行交换。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// February,14,2019
const int maxn=10010;
int pos[maxn],sub[maxn];
int main()
{
    // freopen("交换瓶子/10.in","r",stdin);
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++) {scanf("%d",&pos[i]);sub[pos[i]]=i;}
    for(int i=1;i<=n;i++)
    {
        if(pos[i]==i) continue;
        sub[pos[i]]=sub[i];
        swap(pos[i],pos[sub[i]]);
        sub[i]=i;
        ++ans;
    }
    cout<<ans;
    return 0;
}