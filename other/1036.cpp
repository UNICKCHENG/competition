#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// January,26,2019
const int maxn=1010;
int tree[maxn];

inline void per_print(int k,bool& first)
{
    if(tree[k]<=0) return;
    if(!first) printf(" ");
    else first=false;
    printf("%d",tree[k]);
    per_print(2*k,first);
    per_print(2*k+1,first);
}

inline void in_print(int k,bool& first)
{
    if(tree[k]<=0) return;
    in_print(2*k,first);

    if(!first) printf(" ");
    else first=false;
    printf("%d",tree[k]);

    in_print(2*k+1,first);
}

inline void post_print(int k,bool& first)
{
    if(tree[k]<=0) return;
    post_print(2*k,first);
    post_print(2*k+1,first);

    if(!first) printf(" ");
    else first=false;
    printf("%d",tree[k]);
}
int main()
{
    // freopen("1.in","r",stdin);
    bool first;
    int T,n;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        for(int j=1;j<=n;j++) scanf("%d",&tree[j]);
        printf("Case #%d:",i);
        first=true;printf("\n");
        per_print(1,first);
        first=true;printf("\n");
        in_print(1,first);
        first=true;printf("\n");
        post_print(1,first);
        printf("\n");
    }
    return 0;
}