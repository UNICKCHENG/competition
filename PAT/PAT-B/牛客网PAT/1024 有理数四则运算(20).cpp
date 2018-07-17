/**
 * 1024 有理数四则运算(20)
 * https://www.nowcoder.com/pat/6/problem/4060
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.17,2018
char op[]={'+','-','*','/'};
long long gcd(long long a,long long b){return a==0?b:gcd(b%a,a);}
//进行相关运算
void fun(int b,int a,int d,int c,int& fenzi,int& fenmu,char fg)
{
	int tmp;
	switch(fg)
	{
		case '+':
			if(b==0) {fenzi=d;fenmu=c;break;}
			if(d==0){fenzi=b;fenmu=a;break;}
			tmp=gcd(a*d+b*c,a*c);
			fenzi=(a*d+b*c)/tmp;
			fenmu=a*c/tmp;
			if(fenmu<0) {fenzi*=-1;fenmu*=-1;}
			break;
		case '-':
			if(b==0) {fenzi=-d;fenmu=c;break;}
			if(d==0){fenzi=b;fenmu=a;break;}
			tmp=gcd(b*c-a*d,a*c);
			fenzi=(b*c-a*d)/tmp;
			fenmu=a*c/tmp;
			if(fenmu<0) {fenzi*=-1;fenmu*=-1;}
			break;
		case '*':
			if(b==0||d==0) {fenzi=0;fenmu=1;break;}
			tmp=gcd(b*d,a*c);
			fenzi=b*d/tmp;
			fenmu=a*c/tmp;
			if(fenmu<0) {fenzi*=-1;fenmu*=-1;}
			break;
		case '/':
			if(b==0&&d!=0){fenzi=0;fenmu=1;break;}
			if(d==0){fenzi=0;fenmu=0;break;}
			tmp=gcd(b*c,a*d);
			fenzi=b*c/tmp;
			fenmu=a*d/tmp;
			if(fenmu<0) {fenzi*=-1;fenmu*=-1;}
			break;
	}
}
//将假分数转换成真分数
int tran(int& b,int& a)
{
	int fg=1;
	if(b<0){fg=-1;b=-b;}
	int k=0;
	if(b==0) return k;
	int tmp=gcd(b,a);//约分
	b/=tmp;a/=tmp;
	if(b<a) b*=fg;
	else {k=b/a;b%=a;b*=fg;}
	if(b==0) k*=fg;
	return k;
}
//按要求输出
void print(int k,int b,int a)
{
	if(a==0) {printf("Inf");return ;}
	if(b==0) {if(k<0)printf("(%d)",k);else printf("%d",k); return ;}
	int fg=b;
	if(fg<0){printf("(-");b=-b;}
	if(k) printf("%d ",k);
	printf("%d/%d",b,a);
	if(fg<0) printf(")");
}
int main()
{
	freopen("1.txt","r",stdin);
	int a,b,c,d;
	while(scanf("%d/%d %d/%d",&b,&a,&d,&c)!=EOF)
	{
		int tm_a=a,tm_b=b,tm_c=c,tm_d=d;
		int fenzi,fenmu,k1,k2,k3;
		k1=tran(tm_b,tm_a);
		k2=tran(tm_d,tm_c);
		for(int i=0;i<4;i++)
		{
			fun(b,a,d,c,fenzi,fenmu,op[i]);//加减乘除
			//printf("%d %d\n",fenzi,fenmu);
			k3=tran(fenzi,fenmu);
			print(k1,tm_b,tm_a);
			printf(" %c ",op[i]);
			print(k2,tm_d,tm_c);
			printf(" = ");
			print(k3,fenzi,fenmu);
			printf("\n");
		}
	}
	return 0;
}