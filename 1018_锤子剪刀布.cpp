/**
	输入格式： 
	输入第1行给出正整数N（<=105），即双方交锋的次数。
	随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，
	第1个字母代表甲方，第2个代表乙方，中间有1个空格。 
	输出格式： 
	输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
	第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。 
	
	输入样例：
	10
	C J
	J B
	C B
	B B
	B C
	C C
	C B
	J B
	B C
	J J
	输出样例：
	5 3 2
	2 3 5
	B B
**/ 
//zhicheng
//Mar.10,2018 
#include<iostream>
#include<string>
#include<vector> 
using namespace std;

//比大小 
int _fun(char a,char b)
{
	if(a==b) return 0;
	else if(a=='C'&&b=='J'||a=='J'&&b=='B'||a=='B'&&b=='C') return 1;
	else return 2; 
}

//输出出现次数最多的字母 
void print(int c,int j,int b)
{
	if(b>=j&&b>=c) cout<<"B";
	if(c>=j&&c>b)cout<<"C";
	if(j>c&&j>b) cout<<"J";
}

int main()
{
	int n;
	while(cin>>n)
	{
		char a,b;
		int draw=0,win=0,lose=0;//平，赢，输 
		int c1,j1,b1;
		int c2,j2,b2;
		c1=c2=j1=j2=b1=b2=0;
//input
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			int flg=_fun(a,b);
			switch(flg)
			{
				case 0:draw++;break;
				case 1:win++;
					switch(a)
					{
						case 'C':c1++;break;
						case 'J':j1++;break;
						case 'B':b1++;break;
					}
					break;
				case 2:lose++;
					switch(b)
					{
						case 'C':c2++;break;
						case 'J':j2++;break;
						case 'B':b2++;break;
					}
					break;
			}
		}
//output the result 
		cout<<win<<" "<<draw<<" "<<lose<<endl;//甲 
		cout<<lose<<" "<<draw<<" "<<win<<endl;//乙 
		print(c1,j1,b1);
		cout<<" ";
		print(c2,j2,b2);
		cout<<endl;
	}
	return 0;
}
