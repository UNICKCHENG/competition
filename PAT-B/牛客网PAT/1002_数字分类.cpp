/** 1002	数字分类 (20)
 ** https://www.nowcoder.com/pat/6/problem/4078
 **/

#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jun.26,2018

int a1,a2,a3,a4,a5;
int num2,num4;

void fun(int n)
{
	int se=n%5;
	switch(se)
	{
		// 能被5整除的数字中所有偶数的和
		case 0:
			if(n%2==0) a1+=n;break;
		// 将被5除后余1的数字按给出顺序进行交错求和
		case 1:
			num2%2==0?a2+=n:a2-=n;num2++;break;
		// 被5除后余2的数字的个数
		case 2:
			a3++;break;
		// 被5除后余3的数字的平均数，精确到小数点后1位
		case 3:
			a4+=n;num4++;break;
		// 被5除后余4的数字中最大数字 
		case 4:
			if(n>a5) a5=n;break;
	}
}
int main()
{
	freopen("1.txt","r",stdin);
	int N;
	while(cin>>N)
	{
		a1=a2=a3=a4=a5=num2=num4=0;
		int x;
		for(int i=0;i<N;i++)
		{
			cin>>x;
			fun(x);
		}
		
		if(a1==0) printf("N ");else printf("%d ",a1);
		if(num2==0) printf("N ");else printf("%d ",a2);//避免因交错求和为0而带来错误
		if(a3==0) printf("N ");else printf("%d ",a3);
		if(a4==0) printf("N ");else printf("%.1lf ",a4*1.0/num4);
		if(a5==0) printf("N\n");else printf("%d\n",a5);
	}
	return 0;
}