/**
 * title: 1153 Decode Registration Card of PAT(25)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
 * 题目大意：给定一组考试信息（考号+分数），按照三种模式进行归类查询
 *           -第一种查询，按照T,A,B三类进行归类，根据需要输出某一类的所有考试信息（排序规则如cmp1）
 *           -第二中查询，按照测试场地编号（ the test site number）进行归类，已知某一测试场地编号，打印该编号下的考生数和此处考生的总分
 *           -第三种查询，按照日期进行归类，已知某一天的日期，按规则打印出该日期下的测试场地编号和本场地的考生人数(排序规则如cmp2)
 * 解题思路：查询+排序。属于PAT考察风格，没有太多技巧但并不好解决。考虑到时间上的限制，在读入每个考生信息时就进行适当的归类,避免读完再操作所带来的时间浪费。
 *          对于第一种查询，设立三个不定量数组T,A,B进行分类存储，届时对每个数组排序后输出便可
 *          对于第二种查询，采用哈希映射，用num2,sco2分别映射各个测试场地的人数和总分
 *          对于第三种查询，同样采用哈希映射，不过注意的是映射的下标为 日期+测试场地 组成的一个新的整数，主要为了防止不同日期同一测试场地的数据混乱，其余操作部分则与第二种查询模式一致 
 *          需要注意的是，什么时候打印出 NA，虽然简单但一定得处理好
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;
// zhicheng
// January,11,2018
typedef struct testees{
    char id[15];
    int sco;
}t;
typedef struct date{
    int da;
    int sz;
}d;
vector<t> T,A,B;// 分别存放T,A,B三类testees的信息
vector<d> D[10000];// 存放每个日期下的size
map<int,int> num2,sco2,da;
map<long long int,int>num3;
map<long long int,bool> vis32;
map<int,bool> vis2,vis3;

inline void scan(int n)
{// 扫描数据并进行一定的处理
    t tmp;d dmp;int tsz;int tda;int cnt=0;
    for(int v=1;v<=n;v++)
    {
        scanf("%s %d",tmp.id,&tmp.sco);
        switch(tmp.id[0])
        {// 按T,A,B类别存放
            case 'T':T.push_back(tmp);break;
            case 'A':A.push_back(tmp);break;
            case 'B':B.push_back(tmp);break;
        }
        tsz=(tmp.id[1]-'0')*100+(tmp.id[2]-'0')*10+(tmp.id[3]-'0');
        tda=(tmp.id[4]-'0')*100000+(tmp.id[5]-'0')*10000+(tmp.id[6]-'0')*1000+(tmp.id[7]-'0')*100+(tmp.id[8]-'0')*10+(tmp.id[9]-'0');
        //printf("---%d %d---\n",tsz,tda);
        // 以下完成统计同类size的人数和总分
        if(vis2[tsz]==false) {num2[tsz]=0;sco2[tsz]=0;vis2[tsz]=true;}
        num2[tsz]++;sco2[tsz]+=tmp.sco;
        // 以下完成统计同日期下的size，以及同类size的人数
        long long int tt=tda*1000+tsz;dmp.da=tda;dmp.sz=tsz;
        if(vis3[tda]==false) {da[tda]=cnt++;vis3[tda]=true;}
        if(vis32[tt]==false) {D[da[tda]].push_back(dmp);num3[tt]=0;vis32[tt]=true;}
        num3[tt]++;
    }
}
bool cmp1(t a,t b)
{// 同等级下排名规则
    if(a.sco!=b.sco) return a.sco>b.sco;
    return strcmp(a.id,b.id)<0;
}
bool cmp2(d a,d b)
{// 同日期下size排名规则
    int ta=a.da*1000+a.sz,tb=b.da*1000+b.sz;
    if(num3[ta]!=num3[tb]) return num3[ta]>num3[tb];
    return a.sz<b.sz;
}
int main()
{
    // freopen("1.in","r",stdin);
    int n,m,type;string term;
    scanf("%d %d",&n,&m);
    scan(n);
    for(int v=1;v<=m;v++)
    {
        int tmp;d demp;
        cin>>type>>term;
        printf("Case %d: %d %s\n",v,type,term.c_str());
        switch(type)
        {
            case 1:
                switch(term[0])
                {
                    case 'T':
                        if(T.size()==0){printf("NA\n");continue;}
                        sort(T.begin(),T.end(),cmp1);
                        for(int i=0;i<T.size();i++)
                            printf("%s %d\n",T[i].id,T[i].sco);
                        break;
                    case 'A':
                        if(A.size()==0){printf("NA\n");continue;}
                        sort(A.begin(),A.end(),cmp1);
                        for(int i=0;i<A.size();i++)
                            printf("%s %d\n",A[i].id,A[i].sco);
                        break;
                    case 'B':
                        if(B.size()==0){printf("NA\n");continue;}
                        sort(B.begin(),B.end(),cmp1);
                        for(int i=0;i<B.size();i++)
                            printf("%s %d\n",B[i].id,B[i].sco);
                        break;
                    default:printf("NA\n");break;
                }
                break;
            case 2:
                tmp=stoi(term);
                if(num2[tmp]==0) printf("NA\n");
                else printf("%d %d\n",num2[tmp],sco2[tmp]);
                break;
            case 3:
                tmp=stoi(term);
                if(vis3[tmp]==false){printf("NA\n");continue;}
                sort(D[da[tmp]].begin(),D[da[tmp]].end(),cmp2);
                for(int i=0;i<D[da[tmp]].size();i++)
                {
                    demp=D[da[tmp]][i];
                    printf("%d %d\n",demp.sz,num3[tmp*1000+demp.sz]);
                }
                break;
        }
    }
    return 0;
}