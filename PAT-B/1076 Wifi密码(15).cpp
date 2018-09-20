/**
 * 1076 Wifi密码(15)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805262622244864
 * 解题思路:水题~
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,5,2018
int main()
{
    char a[3];int n;
    for(scanf("%d",&n);n;n--)
    {
        for(int i=0;i<4;i++)
        {
            scanf("%s",a);
            if(a[2]!='T') continue;
            printf("%d",a[0]-'A'+1);
        }
    }
    printf("\n");
    return 0;
}