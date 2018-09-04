/**
 * 1010 Radix (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include <cctype>
#include<cmath>
using namespace std;
//zhicheng
//Jul.27,2018
// m进制的ss转为10进制
long long int transform(string ss,long long m)
{
	long long int sum=0;
	for(int i=0;i<ss.length();i++)
	{
		if(ss[i]>='0'&&ss[i]<='9') sum=sum*m+ss[i]-'0';
		else sum=sum*m+ss[i]-'a'+10;
	}
	return sum;
}

// 找到令两个数值相等的进制数。在查找的过程中，使用二分查找算法
long long find_radix(long long int num,string s2)
{
	char it=*max_element(s2.begin(),s2.end());
	long long low=(isdigit(it)?it-'0':it-'a'+10)+1;
	long long high=max(num,low);
	while(low<=high)
	{
		long long mid=(low+high)/2;
		long long t=transform(s2,mid);
		if(t<0||t>num) high=mid-1;// 溢出或者过大
		else if(t==num) return mid;
		else low=mid+1;
	}
	return -1;
}
int main()
{
	string n1,n2;long long tg,rd;
	while(cin>>n1>>n2>>tg>>rd)
	{
		long long re=tg==1?find_radix(transform(n1,rd),n2):find_radix(transform(n2,rd),n1);
		if(re!=-1) printf("%lld\n",re);
		else printf("Impossible\n");
	}
	return 0;
}
