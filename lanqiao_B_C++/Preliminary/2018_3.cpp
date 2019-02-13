#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
int main()
{
    // freopen("1.in","r",stdin);
    int tmp,num2=0,num5=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            scanf("%d",&tmp);
            while(1)
            {
                if(tmp%5==0){tmp/=5;num5++;}
                else if(tmp%2==0){tmp/=2;num2++;}
                else break;
            }
        }
    printf("%d\n",num2<num5?num2:num5);
    return 0;
}