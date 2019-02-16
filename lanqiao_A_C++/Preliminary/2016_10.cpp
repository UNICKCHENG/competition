/**
 * 最大比例
 * 算法设计：GCD
 * 令q=q1/q2的形式，如此一来，先排序，然后把 a[i]/a[0] 表示为 q^x，即 (q1/q2)^x，把分数进行化简，将分子存入q1数组中，分母存入q2数组中
 * 对数组q1进行辗转相除，求出最大的整数 A，使得存在x使 A^x=q1[i],同理对q2进行辗转相除，得到满足条件的整数B，则 A/B 便是题目要求的最大公比
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
// zhicheng
// February,17,2019
const int maxn=105;
ull a[maxn],q1[maxn],q2[maxn];
ull stein(ull a,ull b)
{// 求gcd
    if(a<b) a^=b,b^=a,a^=b;  //交换，使a为较大数； 
    if(b==0)return a; //当相减为零，即两数相等时，gcd=a； 
    if((!(a&1))&&(!(b&1))) return stein(a>>1,b>>1)<<1;  //注意最后的左移，在递归返回过程中将2因子乘上;
    else if((!(b&1)))return stein(a,b>>1); 
    else if((!(a&1)))return stein(a>>1,b);
    else return stein(a-b,b);        
}
ull fun(ull a,ull b)
{
    if(a==b) return a;
    return fun(min(b/a,a),max(b/a,a));
}
int main()
{
    // freopen("最大比例/10.in","r",stdin);
	// freopen("最大比例/10.out","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%llu",&a[i]);
    sort(a,a+n);
    if(a[0]==a[n-1]){printf("1/1\n");return 0;}// 最大公比为1的特例
    for(int i=1;i<n;++i)
    {
        if(a[0]==a[i]) continue;
        ull g=stein(a[0],a[i]);
        q1[cnt]=a[i]/g;
        q2[cnt]=a[0]/g;
        ++cnt;
    }
    ull A=q1[0],B=q2[0];
    for(int i=1;i<cnt;++i)
    {
        A=fun(A,q1[i]);
        B=fun(B,q2[i]);
    }
    printf("%llu/%llu\n",A,B);
    return 0;
}