#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
// zhicheng
// January,26,2019
const int maxn=1010;
int tree[maxn],n;

void read(int k)
{
    if(k>n) return;
    read(2*k);
    scanf("%d",&tree[k]);
    read(2*k+1);
}
int main()
{
    // freopen("1.in","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        read(1);
        printf("Case #%d: ",i);
        for(int i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",tree[i]);
        }
        printf("\n");
    }
    return 0;
}