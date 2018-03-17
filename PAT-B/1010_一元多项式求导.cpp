#include<iostream>
/**
	设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
	
	输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
	输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
	
	输入样例：
	3 4 -5 2 6 1 -2 0
	输出样例：
	12 3 -10 1 6 0
**/
//zhicheng
//Mar.8,2018
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int temp;
	vector<int> a;
	for(int i=0;;i++)
	{
		cin>>temp;
		a.push_back(temp);
		if(getchar()=='\n') break;
	}
	//零多项式处理 
	if(a[1]==0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}
	//多项式处理 
	for(int i=0;i<a.size()-1;i+=2)
	{
		if(a[i+1]<1) continue;
		cout<<a[i]*a[i+1]<<" "<<a[i+1]-1;
		//判断是空格或是换行 
		if(i==a.size()-3||a[i+3]-1>=0) cout<<" ";
		else cout<<endl; 
	}
	return 0;
}
