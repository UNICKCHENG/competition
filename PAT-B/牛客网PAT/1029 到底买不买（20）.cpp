/** 
 * 1029 到底买不买（20）
 * https://www.nowcoder.com/pat/6/problem/4065
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.20,2018
bool fun(string s1,string s2,int& n)
{
  n=0;
  bool fg=true;
  for(int i=0,j;i<s2.length();i++)
  {
    for(j=0;j<s1.length();j++) if(s2[i]==s1[j]) {s1[j]='*';break;}
    if(j<s1.length()) continue;
    //无法组成
    fg=false;
    n++;
  }
  if(fg)//可以组成
    for(int i=0;i<s1.length();i++) if(s1[i]!='*') n++;
  //cout<<s1<<" "<<s2<<endl;
  return fg;
}
int main()
{
  string s1,s2;
  while(cin>>s1>>s2)
  {
    int n;
    bool fg=fun(s1,s2,n);
    if(fg) printf("Yes ");
    else printf("No ");
    printf("%d\n",n);
  }
  return 0;
}