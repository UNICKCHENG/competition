#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int a=0;a<=floor(sqrt(n)/2);a++)
    {
        for(int d=sqrt(n);d>=ceil(sqrt(n)/2);d--)
        {
            for(int b=a;b<=d;b++)
            {
                for(int c=b;c<=d;c++)
                {
                    if(a*a+b*b+c*c+d*d==n)
                    {
                        printf("%d %d %d %d\n",a,b,c,d);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}