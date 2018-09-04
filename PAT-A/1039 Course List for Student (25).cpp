/**
 * 1039 Course List for Student (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416
 * 题目大意:已知每门课选课学生的名单,现在给定一组学生名单,输出他们的所选课程的情况(所选课程总数+哪些课程(从小到大排序))
 * 解题思路:因为时间限制在200ms之内,只能牺牲空间节约时间,故不能用string,cin,cout,所以采用哈希表处理将姓名字符串对应到整型
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// August 21,2018
const int maxn=26*26*26*10+10;
vector<int> ma[maxn];// 记载每位学生选课情况
int getid(char* name)
{// HASH表
    int id=0;
    for(int i=0;i<3;i++) id=26*id+(name[i]-'A');
    id=id*10+(name[3]-'0');
    return id;
}
int main()
{
    freopen("1.in","r",stdin);
    int numb,cour;char name[4];
    for(scanf("%d %d",&numb,&cour);cour;cour--)
    {// 获取学生选课情况
        int id,stu_num;
        for(scanf("%d %d",&id,&stu_num);stu_num;stu_num--)
        {
            scanf("%s",name);
            ma[getid(name)].push_back(id);
        }
    }
    // 输出需要查询的学生的选课情况
    for(int i=0;i<numb;i++)
    {
        scanf("%s",name);printf("%s",name);
        int na=getid(name),len=ma[na].size();
        if(!len){printf(" 0\n");continue;}
        printf(" %d",len);
        sort(ma[na].begin(),ma[na].end());
        for(int i=0;i<len;i++) printf(" %d",ma[na][i]);
        printf("\n"); 
    }
    return 0;
}
