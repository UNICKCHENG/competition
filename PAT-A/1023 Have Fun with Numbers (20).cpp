/**
 * 1023 Have Fun with Numbers (20)（20 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992
 * https://www.nowcoder.com/pat/1/problem/4006
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
//zhicheng
//Aug.6,2018
//将原先的数字乘以２之后存放至re数组中，最高位存放在ans中
bool doubler(char ss[],char* re,int& ans)
{
    int book1[10]={0},book2[10]={0};
    int len=strlen(ss);
    re[len]='\0';
    for(int i=len-1;i>=0;i--)
    {
    	ans+=(ss[i]-'0')*2;
    	re[i]=ans%10+'0';
    	ans/=10;
    	book1[ss[i]-'0']++;
    	book2[re[i]-'0']++;
    }
    if(ans)book2[ans]++;
    for(int i=0;i<10;i++)if(book1[i]!=book2[i])return false;
    return true;
}
int main()
{
    char ss[21],re[22];int carry=0;
    scanf("%s",ss);
    bool flg=doubler(ss,re,carry);
    if(flg) printf("Yes\n");
    else printf("No\n");
    if(carry)printf("%d",carry);
    printf("%s",re);
    printf("\n");
    return 0;
}
