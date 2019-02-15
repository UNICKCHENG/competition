/**
 * 螺旋折线
 * 算法设计：O(1)
 * 把每个周期看成一个正方形，这样一来题目就变得非常简单了，但是需要注意数据的范围。
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
// zhicheng
// February,15,2019
ull dis(int x,int y)
{
    int tx=x>0?x:-x,ty=y>0?y:-y;
    ull r=tx>ty?tx:ty;--r;
    ull ans=4*r*r+4*r; ++r; 
    if(x==-r&&y==-r) ans+=2*r*4;
    // 判断是正方形的第几条边
    else if(x==-r) ans+=y+r;
    else if(y==r) ans+=2*r+x+r;
    else if(x==r) ans+=2*2*r+r-y;
    else if(y==-r) ans+=3*2*r+r-x;
    return ans;
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%llu\n",dis(x,y));
    return 0;
}