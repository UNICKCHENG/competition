
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024
int count=0;

void f(int a[], int k, int m, char b[])
{
	int i,j;
	
	if(k==N){ 
		b[M] = 0;
		//if(m==0) printf("%s\n",b);
		if(m==0)
		{
			printf("%s\n",b);
			count++;
		}
		
		return;
	}
	
	for(i=0; i<=a[k]; i++){
		for(j=0; j<i; j++) b[M-m+j] = k+'A';
		f(a,k+1,m-i,b);
	//	______________________;  //���λ��
	}
}
int main()
{	
	int  a[N] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,M,b);
	printf("%d",count);
	return 0;
}
