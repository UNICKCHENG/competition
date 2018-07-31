/**
 * 1015 Reversible Primes (20)（20 point(s)）
 * PTA:https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
 * nowcoder: https://www.nowcoder.com/pat/1/problem/3989
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.31,2018
bool is_Prim(int n)
{
    if(n<=1) return false;
    for(int i=2;i<=n/2;i++) if(n%i==0) return false;
    return true;
}

int shift(int n,int d)
{
    string re="";
    while(n)
    {
        re.push_back(n%d+'0');
        n=n/d;
    }
    for(int i=0;i<re.length();i++) n=(re[i]-'0')+n*d;
    //cout<<"##"<<n<<endl;
    return n;
}
int main()
{
    int n,d;
    while(scanf("%d %d",&n,&d)==2) { is_Prim(n)&&is_Prim(shift(n,d))?printf("Yes\n"):printf("No\n");}
    return 0;
}
