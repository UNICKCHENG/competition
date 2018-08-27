/**
 * 1050 String Subtraction (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152
 * 题目大意:去除字符串S1中在S2中也出现的字符
 * 解题思路:哈希散列
 */
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
// zhicheng
// August 27,2018
map<char,bool> m;
int main()
{
    string ss;
    getline(cin,ss);
    char c=getchar();
    while(c!='\n') { m[c]=true;c=getchar();}
    for(int i=0;i<ss.length();i++)
        if(m[ss[i]]!=true) printf("%c",ss[i]);
    printf("\n");
    return 0;
}
