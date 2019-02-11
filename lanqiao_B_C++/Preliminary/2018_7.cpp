#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;

const int FLG=8;

ull dis(int x,int y)
{
    ull ans=0;
    int r=abs(x)>abs(y)?abs(x)-1:abs(y)-1;
    ans+=4*r*r+4*r;
    if(x==-(r+1)&&y==-(r+1)) ans+=(r+1)*FLG;// 特殊点
    else{
        // 判断是正方形的第几条边
        if(x==-(r+1)) ans+=y+(r+1);
        else if(y==(r+1)) ans+=2*(r+1)+x+(r+1);
        else if(x==(r+1)) ans+=2*2*(r+1)+(r+1)-y;
        else if(y==-(r+1)) ans+=3*2*(r+1)+(r+1)-x;
    } 
    return ans;
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%llu\n",dis(x,y));
    return 0;
}