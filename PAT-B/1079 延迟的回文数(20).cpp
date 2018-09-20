/**
 * 1079 延迟的回文数(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805261754023936
 * 解题思路:首先明确数字的长度是在1000位以内,所以只能用字符串存储这个数字进行一系列操作
 *         (1) 首先判断数字和他的反转后的数字是否一致,及是否为回文串
 *         (2) 如果(1)返回的是不是,将这两个数字相加,得出新的一个数字,再次判断,直到连续这样操作10次或者得到了一个回文数,则结束循环
 *         (3) 需要注意的是,可能本身输入的数字便是回文数,则直接那要求输出即可
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// September,5,2018
int main()
{
    string ss,tmp;int n=0;
    getline(cin,ss);
    tmp=ss;
    reverse(tmp.begin(),tmp.end());
    bool flg=ss==tmp?true:false;
    while(n<10&&!flg)
    {
        string re="";int cur=0;char c;
        for(int i=ss.length()-1;i>=0;i--)
        {
            cur+=(ss[i]-'0')+(tmp[i]-'0');
            c=cur%10+'0';
            re=c+re;
            cur/=10;
        }
        if(cur) {c=cur+'0';re=c+re;}
        printf("%s + %s = %s\n",ss.c_str(),tmp.c_str(),re.c_str());
        ss=tmp=re;
        reverse(tmp.begin(),tmp.end());
        flg=ss==tmp?true:false;
        n++;
    }
    if(flg) printf("%s is a palindromic number.\n",ss.c_str());
    else printf("Not found in 10 iterations.\n");
    return 0;
}