/**
 * 四平方和
 * 0~sqrt(n)遍历三层for循环，这样的暴力求解足以，时间复杂度为O(n^1.5)。下面程序进行了一点优化。
*/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c,n;
    scanf("%d",&n);
    double sq=sqrt(1.0*n);
    if(ceil(sq)==floor(sq)) {printf("0 0 0 %d\n",(int)sq);return 0;}
    for(a=0;a<=ceil(sq/2);++a)
    {
        for(b=a;b<=ceil(sq/sqrt(3));++b)
        {
            for(c=b;c<=ceil(sq/sqrt(2));++c)
            {
                int tmp=n-a*a-b*b-c*c;
                if(tmp<0) break;
                double d=sqrt(1.0*tmp);
                if(ceil(d)==floor(d)){printf("%d %d %d %d\n",a,b,c,(int)d);return 0;}
            }
        }
    }
    return 0;
}