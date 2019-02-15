/**
 * 交换瓶子
 * 解题思路：O(n)
*/
#include <iostream>
#include <cstdio>
using namespace std;
// zhicheng
// February,15,2019
int pos[10010];
int main()
{
	int n,ans=0;scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",pos+i);
    for(int i=1;i<=n;++i)
    {
        while(pos[i]!=i)
        {
            swap(pos[i],pos[pos[i]]);
            ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}