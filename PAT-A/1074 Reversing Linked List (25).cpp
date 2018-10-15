/**
 * 1074 Reversing Linked List (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144
 * 题目大意：给定一段链表，要求将链表中每连续K个节点一组进行反转，如果不足K个节点则不进行反转，输出所有节点反转后的结果
 * 解题思路：链表操作。首先构建好链表，并按链表的顺序存好各个节点的地址值。其后便是相关操作和输出格式问题。
 *          - 相关操作：首先求出一段链表中有多少组需要反转，然后在对每组中的各个节点的地址按原先顺序的逆序输出。
 *          - 格式输出，只要不是首节点，都一致按 printf(“%05d\n%05d %d”,node_addr,node_addr,node_val) 格式输出
 *                     最终的首节点一种是进行反转后得到（K<=node_number），一种是未进行反转后得到的(K>node_nbumber)
 *          注意事项；题目虽然输入了N个节点，但未必这N个节点都是链表中的节点，即构成的链表的节点总数 node_number <= N
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// October,15,2018
const int maxn=100000+5;
int da[maxn],ne[maxn],ad[maxn];

int main()
{
    // freopen("1.in","r",stdin);
    int node,n,k,cnt=1;int addr;
    for(scanf("%d %d %d",&node,&n,&k);n;n--)
        cin>>addr>>da[addr]>>ne[addr]; // 初始化链表，并完成构建
    for(int i=node;i!=-1;i=ne[i]) ad[cnt++]=i; // 将链表的各节点地址依次存入数组
    int cycle=(cnt-1)/k;// 一个链表中有几个模块需要发生发转
    for(int i=1;i<=cycle;i++)
    {// 对发生反转部分进行操作
        for(int j=i*k;j>(i-1)*k;j--)
        {
            if(j!=k) printf("%05d\n",ad[j]);
            printf("%05d %d ",ad[j],da[ad[j]]);
        }
    }
    for(int i=cycle*k+1;i<=cnt-1;i++) //对尾部剩余且不发生反转元素进行正常输出
    {
        if(i!=1) printf("%05d\n",ad[i]);
        printf("%05d %d ",ad[i],da[ad[i]]);
    }
    printf("-1\n");
    return 0;
}