#include<stdio.h>
#include<stdlib.h>
int count=0;
int visit[13]={0};//遍历，同一个数据最多遍历四次 
void baoli(int n)
{
	n++;
//	printf("---%d\n",n);
	if(n==14) 
	{
	//	printf("*%d\n",n);
		count++;
		return;	
	}
	for(int i=1;i<14;i++)
	{
		if(visit[i-1]==4) continue;
		visit[i-1]+=1;
	//	printf("1:%d\n",n);
	//	printf("  %d\n",i);
		baoli(n);
	//	printf("2:%d\n",n);
		//system("pause");
		visit[i-1]-=1; 
	}
} 

int main()
{
	baoli(0);
	printf("%d",count);
	return 0;
}
