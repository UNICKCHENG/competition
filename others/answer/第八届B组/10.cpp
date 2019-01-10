#include<cstdio>  
#include<memory.h>   

const int maxn=10000+5;  
int a[maxn],cnt[maxn];  
int main()  
{  
    int n,k,x,ans;  
    memset(cnt,0,sizeof(cnt));  
    scanf("%d %d",&n,&k);  
    ans=a[0]=0;  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&x);  
        a[i]=(a[i-1]+x)%k;  
        ans+=cnt[a[i]];  
        cnt[a[i]]++;  
    }  
    printf("%d\n",ans+cnt[0]);  
    return 0;  
}  