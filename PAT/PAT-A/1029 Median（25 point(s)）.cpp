/**
 * 1029 Median（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968
 * 思路:刚开始思路为,合并两个有序序列,然后根据下标找出中间元素.可是如若合并两个序列,肯定会超空间,此时换一个思路,即与其找下标,不如找中间元素在
 *     合并时所在的位置,这样一来,存好第一个有序序列,对于第二个有序序列是边与第一个序列比较,边记录这些元素在合并时的位置,找到与中间元素对应的位置
 *     并输出结果即可.
 */
#include<cstdio>
#include<iostream>
#include <climits>
#include<vector>
using namespace std;
//zhicheng
//August 13,2018
vector<int> a;

bool is_judge(int cn,int mid,int n)
{
	if(cn==mid) {printf("%d\n",n);return true;}
	return false;
}
int main()
{
	// freopen("1.txt","r",stdin);
	long long int tmp;int len[2],cnt=0,mid;
	scanf("%d",&len[0]);
	for(int i=0;i<len[0];i++){scanf("%lld",&tmp);tmp=min((long long int)INT_MAX,tmp);a.push_back(tmp);}
	scanf("%d",&len[1]);
	if((len[0]+len[1])%2==0) mid=(len[0]+len[1])/2-1;
	else mid=(len[0]+len[1])/2;
	int cn=0;
	while(len[1]--)
	{
		bool flg=false;
		scanf("%lld",&tmp);
		tmp=min((long long int)INT_MAX,tmp);
		while(cnt<len[0]&&a[cnt]<=tmp){is_judge(cn,mid,a[cnt]);cn++;cnt++;}
		is_judge(cn,mid,tmp);
		cn++;
	}
	if(cnt<len[0]) 
		while(cnt<len[0])
		{
			if(is_judge(cn,mid,a[cnt])) break;
			cn++;
			cnt++;
		}
	a.clear();
	return 0;
}
