/**
 * 注意：负数在计算机中采用补码的形式存储
 * 9的9次方 387420489
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

void print(int tmp)
{
    int re[8],cnt=7;
    memset(re,0,sizeof(re));
    if(tmp<0){tmp=-tmp;re[0]=1;}// 如果这个数是负数，将二进制的最高位标为1
    while(tmp)
    {
        re[cnt--]=tmp%2;
        tmp/=2;
    }
    if(re[0]==1)
    {// 负数用补码表示
        cnt=7;
        while(re[cnt]==0) cnt--;// 自右往左找到第一个非零数
        for(int i=0;i<cnt;i++)
        {
            if(re[i]==0) re[i]=1;
            else re[i]=0;
        }
    }
    for(int i=0;i<8;i++) re[i]!=0?printf("%d",re[i]):printf(" ");// 将二进制结果输出，把0输出来可能造成视觉混乱，本处用空格代替0
}
int main()
{
    // freopen("1.in","r",stdin);
    int tmp;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<32;j++) 
        {
            if(j&&j%2==0) printf("\n");
            scanf("%d",&tmp);
            print(tmp);// 作为2进制打印
        }
        printf("\n\n");
    }
    return 0;
}