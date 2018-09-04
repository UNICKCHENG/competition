/**
 * 1036 Boys vs Girls (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016
 * 题目大意:给定一组考生信息(包含name gander id grade),从中选取男生中的最低分,女生中的最高分,并求他们成绩的差值
 * 解题思路:题目很简单,在输入数据时,找到男生中的最低分,女生中的最高分,并存下他们的信息.之后进行输出即可
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 18,2018
int main()
{
  int t,ml_grade=101,fh_grade=-1;string ml_id,fh_id,ml_name,fh_name;
  for(scanf("%d",&t);t;t--)
  {
    string id,na,ge;int gr;
    cin>>na>>ge>>id>>gr;
    if(ge=="M"&&gr<ml_grade) {ml_name=na;ml_id=id;ml_grade=gr;} // 男生中的最低分
    if(ge=="F"&&gr>fh_grade) {fh_name=na;fh_id=id;fh_grade=gr;} // 女生中的最高分
  }
  fh_grade!=-1?cout<<fh_name<<" "<<fh_id<<endl:cout<<"Absent\n"; // 判断是否有女生数据
  ml_grade!=101?cout<<ml_name<<" "<<ml_id<<endl:cout<<"Absent\n"; // 判断是否有男生数据
  fh_grade==-1||ml_grade==101?printf("NA\n"):printf("%d\n",fh_grade-ml_grade);// 输出他们成绩的差值
}
