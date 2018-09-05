/**
 * 1078 字符串压缩与解压(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805262018265088
 * 解题思路:字符串处理题,需要掌握整行读取和字符串遍历
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// September,5,2018
int main()
{
    // freopen("1.in","r",stdin);
    char c,d[1005];
    scanf("%c",&c);getchar();
    cin.getline(d,1005);
    int len=strlen(d);
    switch(c)
    {
        case 'C':
            for(int i=0,j=i;i<len;i=j)
            {
                while(d[i]==d[j]) j++;
                if((j-i)<2) printf("%c",d[i]);
                else printf("%d%c",j-i,d[i]);
            }
            break;
        case 'D':
            for(int i=0;i<len;i++)
            {
                if(d[i]>='0'&&d[i]<='9')
                {
                    int ans=0;
                    while(d[i]>='0'&&d[i]<='9'){ans=ans*10+d[i]-'0';i++;}
                    while(ans--) printf("%c",d[i]);
                } 
                else printf("%c",d[i]);
            }
            break;
    }
    // printf("\n");
    return 0;
}