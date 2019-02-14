/**
 * 四平方和
 * 暴力枚举，O(n^1.5)
*/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
// zhicheng
// Febuary,13,2019
void fun(int n)
{
    if(ceil(sqrt(n))==floor(sqrt(n))) {printf("0 0 0 %d\n",(int)sqrt(n));return;}
        for(int a=0;a<sqrt(n);++a)
            for(int b=a;b<sqrt(n);++b)
                for(int c=b;c<sqrt(n);++c)
                {
                    int tmp=n-a*a-b*b-c*c;
                    double d=sqrt(tmp);
                    if(ceil(d)==floor(d)) {printf("%d %d %d %d\n",a,b,c,(int)d);return;}
                }
}
int main()
{
    int n;
    scanf("%d",&n);
    fun(n);  
    return 0;
}