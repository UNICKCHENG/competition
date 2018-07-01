/**
 * 1007	A除以B (20)
 * https://www.nowcoder.com/pat/6/problem/4043
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.1,2018
int main()
{
	freopen("1.txt","r",stdin);
	string a,q;
	int b,r;
	while(cin>>a>>b)
	{
		int cnt=0;//进位
		if(a[0]-'0'<b&&a.length()==1){cout<<"0 "<<a[0]<<endl;continue;}//特殊情况 A<B
		for(int i=0;i<a.length();i++)
		{
			cnt=cnt*10+(a[i]-'0');
			if(i==0&&cnt<b) continue;//避免商首元素为0
			q.push_back(cnt/b+'0');
			cnt%=b;
		}
		r=cnt;
		cout<<q<<" "<<r<<endl;
		q.clear();
	}
	return 0;
}