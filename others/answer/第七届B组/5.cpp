//t=x[k]; x[k]=x[i]; x[i]=t; 
#include <stdio.h>

void test(int x[])
{
	int a = x[0]*1000 + x[1]*100 + x[2]*10 + x[3];
	int b = x[4]*10000 + x[5]*1000 + x[6]*100 + x[7]*10 + x[8];
	
	if(a*3==b) printf("%d / %d\n", a, b);
}

void f(int x[], int k)
{
	int i,t;
	if(k>=9){
		test(x);
		return;
	}
	
	for(i=k; i<9; i++){
		{t=x[k]; x[k]=x[i]; x[i]=t;}
		f(x,k+1);
		{t=x[k]; x[k]=x[i]; x[i]=t;}//还原上一分布	
		//_____________________________________________ // 填空处
	}
}
	
int main()
{
	int x[] = {1,2,3,4,5,6,7,8,9};
	f(x,0);	
	return 0;
}

