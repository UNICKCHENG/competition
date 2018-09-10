/**
 * 1088 三人行(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/1038429286185074688
 * 解题思路:因为甲的能力值为两位数所以从99到10遍历一遍,凡是满足题意输出即可,若没有则输出"No Solution"
 *        需要注意的是丙的能力值没有说一定为整数
 */
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
// zhicheng
// September,10,2018
int main()
{
    int m,x,y,i;
    scanf("%d %d %d",&m,&x,&y);
    for(i=99;i>=10;i--)
    {
        int tmp=i%10*10+i/10;
        double z=abs(i-tmp)*1.0/x;
        if(tmp!=z*y) continue;
        printf("%d ",i);
        m==i?printf("Ping "):(m>i?printf("Gai "):printf("Cong "));
        m==tmp?printf("Ping "):(m>tmp?printf("Gai "):printf("Cong "));
        m==z?printf("Ping"):(m>z?printf("Gai"):printf("Cong"));
        break;
    }
    if(i<10)printf("No Solution");
    printf("\n");
    return 0;
}