/**
 * 1073 Scientific Notation(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784
 * 题目大意：将科学计数法表示的数字改成常规计数进行表示
 * 解题思路：模拟题。主要是小数点的问题。
 *          - 小数点前移。那么指数多少则在前面补充多少个零
 *          - 小数点后移。
 *              - 变成整数，即无小数点。底数后补充相应的零即可
 *              - 还是小数，即仍存小数点。小数点往后移动指数个位即可
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// October,13,2018
char s[10000+5];
int main()
{
    bool flg=false;int expo=0,cnt;
    scanf("%s",s);
    if(s[0]=='-')printf("-");
    for(cnt=1;s[cnt]!='E';cnt++);
    if(s[cnt+1]=='+') flg=true;
    for(int i=cnt+2,len=strlen(s);i<len;i++) expo=expo*10+(s[i]-'0');

    if(flg==false)
    {// 小数点前移
        printf("0.");
        for(int i=1;i<expo;i++) printf("0");
        for(int i=1;i<cnt;i++) {if(s[i]=='.')continue;printf("%c",s[i]);}
    }
    else if(expo>=(cnt-3))
    {// 小数点后移到全部是整数
        for(int i=1;i<cnt;i++) {if(s[i]=='.')continue;printf("%c",s[i]);}
        for(int i=cnt-3+1;i<=expo;i++) printf("0");
    }
    else 
    {// 小数点后移，但仍有小数点
        for(int i=1;i<=expo+2;i++) {if(s[i]=='.')continue;printf("%c",s[i]);}
        printf(".");
        for(int i=expo+2+1;i<cnt;i++) printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}