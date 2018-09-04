#include<stdio.h>

int w,m,n,distance;

void function()
{
	int cn=1;
	int min=m>n?n:m;
	int max=m>n?m:n;
	int a,b,c,d;
	for(int i=0;;i++)
	{
		if(i%2==0)
			for(int j=0;j<w;j++)
			{
				if(cn==min) 
				{
					a=i;b=j;
				}
				if(cn==max) 
				{
					c=i;d=j;
					printf("%d",c+d-a-b);
					return;
				}
				cn++;
			}
		else
			for(int j=w-1;j>=0;j--)
			{
				if(cn==min) 
				{
					a=i;b=j;
				}
				if(cn==max) 
				{
					c=i;d=j;
					printf("%d",c+d-a-b);
					return;
				}
				cn++;
			}
		
	}
}


int main()
{
	scanf("%d %d %d",&w,&m,&n);
	function();
}
