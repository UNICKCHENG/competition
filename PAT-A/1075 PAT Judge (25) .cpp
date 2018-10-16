/**
 * 1075 PAT Judge (25) 
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032
 * 题目大意：仿照PTA提交的机制。先给定一组考生提交信息，然后按照总分排序，若总分一致，则按照拿到满分的题目数量排序，如若仍是一样，则按照学号排序
 *          在输出的时候，对于所有题目没有提交过或者都没编译通过的话，不对其进行输出显示。注意有考生提交了但为编译通过而显示的成绩为0.
 * 解题思路：排序题。首先对其按输入时顺序对学号进行编号，然后按题目要求对其进行排序，不过在输出的时候需要注意，只要考生存在题目提交且编译通过（该题得分不为负数）则对其输出，
 *          如果题目提交但未编译通过，则按0输出，如果题目为进行提交，则按“-”输出。
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
// zhicheng
// October,16,2018
typedef struct {int id;int pro_sco[6];int sco;int pass;int flg;}stu;
int map_sco[6];
map<int,int> map_stu_id;
stu d[10000+5];

bool comp(stu a,stu b)
{
    if(a.sco!=b.sco) return a.sco>b.sco;
    else if(a.pass!=b.pass) return a.pass>b.pass;
    else return a.id<b.id;
}
int main()
{
    // freopen("1.in","r",stdin);
    int n,k,m,id,cnt=1,pro,score;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=k;i++) scanf("%d",&map_sco[i]);
    while(m--)
    {
        scanf("%d %d %d",&id,&pro,&score);
        if(!map_stu_id[id])
        {// 初始化新增的学生信息
            d[cnt].id=id;
            for(int i=1;i<=k;i++) d[cnt].pro_sco[i]=-2;
            d[cnt].sco=0;d[cnt].pass=0;d[cnt].flg=0;
            map_stu_id[id]=cnt++;
        }
        if(score==-1&&d[map_stu_id[id]].pro_sco[pro]==-2) d[map_stu_id[id]].pro_sco[pro]=-1;// 第一次提交且未通过编译
        else if(score>d[map_stu_id[id]].pro_sco[pro])
        {
            d[map_stu_id[id]].flg=1;// 题目提交过且通过编译
            if(d[map_stu_id[id]].pro_sco[pro]!=-1&&d[map_stu_id[id]].pro_sco[pro]!=-2) 
                d[map_stu_id[id]].sco-=d[map_stu_id[id]].pro_sco[pro];
            d[map_stu_id[id]].sco+=score;
            if(score==map_sco[pro]) d[map_stu_id[id]].pass++;
            d[map_stu_id[id]].pro_sco[pro]=score;
        }
    }
    sort(d+1,d+cnt,comp);
    int rank=1;
    for(int i=1;i<cnt;i++)
    {
        if(d[i].flg==0) continue;
        if(i!=1&&d[i].sco!=d[i-1].sco) rank=i; printf("%d ",rank);
        printf("%05d %d",d[i].id,d[i].sco);
        for(int j=1;j<=k;j++) 
            d[i].pro_sco[j]==-2?printf(" -"):(d[i].pro_sco[j]==-1?printf(" 0"):printf(" %d",d[i].pro_sco[j]));
        printf("\n");
    }
    return 0;
}