/**
 * 1081 检查密码(15)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805261217153024
 * 解题思路:遍历字符串,判断是否满足要求
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
// zhicheng
// September,4,2018
int main()
{
    // freopen("1.in","r",stdin);
    char c[85];int _;
    for(scanf("%d",&_),getchar();_;_--)
    {
        cin.getline(c,85);
        int len=strlen(c);bool flg=true,f1=false,f2=false;
        if(len<6) {printf("Your password is tai duan le.\n");continue;}
        for(int i=0;i<len;i++)
        {
            if(c[i]>='0'&&c[i]<='9') f1=true;
            else if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')) f2=true;
            else if(c[i]!='.') {flg=false;break;}
        }
        if(flg==false) printf("Your password is tai luan le.\n");
        else if(f1&&f2) printf("Your password is wan mei.\n");
        else if(f2&&!f1) printf("Your password needs shu zi.\n");
        else if(f1&&!f2) printf("Your password needs zi mu.\n");
        else printf("Your password is tai luan le.\n");
    }
    return 0;
}