/**
 * 1084 Broken Keyboard(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672
 * 题目大意：给定两个字符串，以第一字符串为参考，输出第二个字符串中未出现的字符，字母以大写形式输出
 * 解题思路：用map映射即可
 */
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<map>
using namespace std;
// zhicheng
// November,12,2018
map<char,bool> m;
int main()
{
    char a[85],b[85],tmp;
    scanf("%s\n%s",a,b);
    for(int i=0,len=strlen(b);i<len;i++) 
    {
        tmp=toupper(b[i]);
        m[tmp]=true;
    }
    for(int i=0,len=strlen(a);i<len;i++)
    {
        tmp=toupper(a[i]);
        if(m[tmp]==false) {printf("%c",tmp);m[tmp]=true;}
    }
    return 0;
}