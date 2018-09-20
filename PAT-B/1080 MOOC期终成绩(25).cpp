/**
 * 1080 MOOC期终成绩(25)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805261493977088
 * 解题思路:一道排序题,基本这样的题目离不开哈希映射和sort排序
 *           -首先存好GP已经满足大于等于200分的学生信息
 *           -后续存入他们的期中和期末成绩,因为G是要不小于60的,所以满足要求的学生必然参加了期末考试 
 *           -注意就一人满足要求的特殊情况
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
// zhicheng
// September,5,2018
typedef struct{string na;int gp;int g;int gm;int gf;}D;
D d[10005];
map<string,int> ma;
bool cmp(D a,D b){return a.g!=b.g?a.g>b.g:a.na<b.na;}
int main()
{
    freopen("1.in","r",stdin);
    int p,m,n,cn=0;
    string c;int g;
    scanf("%d %d %d",&p,&m,&n);
    while(p--)
    {
        cin>>c>>g;
        if(g<200) continue;
        d[cn].na=c;d[cn].gp=g;d[cn].gm=-1;d[cn].gf=-1;d[cn].g=0;
        ma[c]=cn+1;
        cn++;
    }
    while(m--)
    {
        cin>>c>>g;
        if(ma[c]==0) continue;
        d[ma[c]-1].gm=g;
    }
    while(n--)
    {
        cin>>c>>g;
        if(ma[c]==0)continue;
        d[ma[c]-1].gf=g;
        if(d[ma[c]-1].gm>d[ma[c]-1].gf) d[ma[c]-1].g=(d[ma[c]-1].gm*0.4+d[ma[c]-1].gf*0.6+0.5);
        else d[ma[c]-1].g=d[ma[c]-1].gf;
    }
    if(cn>1) sort(d,d+cn,cmp);// 需要注意前面满足要求的学生数目可能为1,因为题意已说至少有一个学生满足要求
    for(int i=0;i<cn;i++)
    {
        if(d[i].g<60) break;
        printf("%s %d %d %d %d\n",d[i].na.c_str(),d[i].gp,d[i].gm,d[i].gf,d[i].g);
    }
    return 0;
}