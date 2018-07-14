/**
 * 21 查验身份证(15) 
 * https://www.nowcoder.com/pat/6/problem/4057
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.14,2018
char M[]={'1','0','X','9','8','7','6','5','4','3','2'};
int a[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

inline bool is_effect(string ss)
{
	int sum =0;
	if(ss.length()!=18) return false;//检查长度是否合格
	for(int i=0;i<ss.length()-1;i++)
	{
		if(ss[i]<'0'||ss[i]>'9') return false;//检查前17位是否全为数字
		sum+=((ss[i]-'0')*a[i])%11;
	}
	if(ss[ss.length()-1]!=M[sum%11]) return false;//检查最后1位校验码是否计算准确
	return true;
}
int main()
{
	freopen("1.txt","r",stdin);
	string ss;int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool fg=true;//记录是否全部合格
		while(n--)
		{
			cin>>ss;
			bool flg=is_effect(ss);
			if(!flg) {fg=false;printf("%s\n",ss.c_str());}
		}
		if(fg) printf("All passed\n");
	}
	return 0;
}