/**1001 A+B和C(15)
  *https://www.nowcoder.com/pat/6/problem/4077
 */
#include<iostream>
#include<cstdio>
using namespace std;
//zhicheng
//Jun.25,2018

int main()
{
	long long a,b,c;
	freopen("1.txt","r",stdin);
	int T;
	while(cin>>T)
	{
		for(int i=1;i<=T;i++) 
		{
			cin>>a>>b>>c;
			if((a+b)>c) cout<<"Case #"<<i<<": true"<<endl;
			else  cout<<"Case #"<<i<<": false"<<endl;
		}
	}
	return 0;
}