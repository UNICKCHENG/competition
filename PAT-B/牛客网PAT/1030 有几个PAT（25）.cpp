/**
 * 1030 有几个PAT（25）
 * https://www.nowcoder.com/pat/6/problem/4066
*/
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.20,2018
const int maxn=1000000007;
int fun(string ss)
{
  int p=0,a=0,t=0;
  for(int i=0;i<ss.length();i++)
  {
    if(ss[i]=='P') p=(p+1)%maxn;
    if(p&&ss[i]=='A')a=(a+p)%maxn;
    if(a&&ss[i]=='T')t=(t+a)%maxn;
  }
  return t%maxn;
}
int main()
{
  string ss;
  while(cin>>ss) printf("%d\n",fun(ss));
  return 0;
}