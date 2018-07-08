/**
 * 1014 科学计数法 (20)
 * https://www.nowcoder.com/pat/6/problem/4050
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.8,2018
int main()
{
	freopen("1.txt","r",stdin);
	string ss;
	while(cin>>ss)
	{
		string s1,s2;//数字和指数
		int flg2=1,cnt=0;//指数正负的标志
		if(ss[cnt++]=='-')printf("-");
		while(ss[cnt]!='E') s1.push_back(ss[cnt++]);
		if(ss[++cnt]=='-')flg2=0;
		while(ss[++cnt]!='\0')s2.push_back(ss[cnt]);
		double b=stoi(s2);
		//cout<<s1<<" "<<s2;
		if(flg2)
		{//小数点往后移
			if(b>=s1.length()-1)
			{//可以去小数点，甚至补零进位
				for(int i=0;i<s1.length();i++){if(s1[i]=='.') continue;cout<<s1[i];}
				for(int i=0;i<b-(s1.length()-2);i++)printf("0");
			}
			else 
			{//无法去除小数点
				int te=0;
				cout<<s1[te++];
				while(b--){cout<<s1[++te];}
				cout<<".";
				while(s1[++te]!='\0')cout<<s1[te];
			}
		}
		else
		{//小数点往前移
			printf("0.");
			for(int i=0;i<b-1;i++) printf("0");
			for(int i=0;i<s1.length();i++){if(s1[i]=='.') continue;cout<<s1[i];}
		}
		cout<<endl;
	}
	return 0;
}