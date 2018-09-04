/**
 * 1019. 数字黑洞 (20)
 * https://www.nowcoder.com/pat/6/problem/4045
 */
#include<cstdio>
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
//zhicheng
//Jul.3,2018
string toString(int n)
{
	stringstream stream;
	stream<<n;
	return stream.str();
}
int main()
{
	string ss;
	while(cin>>ss)
	{
		int te;
		do
		{
			if(ss.size()!=4) ss.append(4-ss.size(),'0');//不足4位自动补全
			sort(ss.begin(),ss.end());//升序
			int a=stoi(ss);
			reverse(ss.begin(),ss.end());//降序
			int b=stoi(ss);
			te=b-a;
			printf("%04d - %04d = %04d\n",b,a,te);
			ss=toString(te);
		}while(te!=6174&&te);
	}
	return 0;
}






/**版本一
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

//d为1 则是按非递减排序
int sort_re(int te,int d)
{
	int a[4]={0},cnt=0;
	while(te) {a[cnt++]=te%10;te/=10;}
	if(d) sort(a,a+4,greater<int>());//从大到小
	else sort(a,a+4,less<int>());//从小到大
	te=0;cnt=4;
	while(cnt) te=te*10+a[--cnt];
	return te;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int te=n;
		do
		{
			int a=sort_re(te,0);
			int b=sort_re(te,1);
			te=a-b;
			printf("%04d - %04d = %04d\n",a,b,te);
		}while(te!=6174&&te!=0);

	}
	return 0;
}
*/