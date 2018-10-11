/**
 * 1071 Speech Patterns(25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616
 * 题目大意:统计一句话中出现最多的单词,并且输出重复次数.如果次数一样多,则输出字典序最小的那个.注意单词只可以由[0-9 A-Z a-z]组成.
 * 解题思路:map映射.将一句话拆成一个个单词,并统计单词出现的个数即可.
 *         - 在统计单词的时候需要将字母统一为小写字母或者大写字母
 *         - 一个一个字符的读取构成一个完整的单词,从而进行统计该单词出现的次数
 *         - 在读取到非[0-9 A-Z a-z]中的字符时候,也就标志着单词读取完毕,开始统计出现次数
 */
#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>
#include<map>
using namespace std;
// zhicheng
// October,10,2018
map<string,int> m;
int main()
{
    string re="",s,tmp="";int num=0;
    getline(cin,s);
    for(int i=0,len=s.length();i<len;i++)
    {
        if(isalnum(s[i])){s[i]=tolower(s[i]);tmp=tmp+s[i];}// 将一个个字母创成全是小写的单词
        if(tmp!=""&&(!isalnum(s[i])||i==len-1))// 标志前一个单词读取结束,开始进行统计该单词出现的次数
        {
            m[tmp]++;
            if((num<m[tmp])||(num==m[tmp]&&re>tmp)){num=m[tmp];re=tmp;}
            tmp="";
        }
    }
    printf("%s %d\n",re.c_str(),num);
    return 0;
}