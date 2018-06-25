#include<stdio.h>
int main()
{
	int count=0;
	for(int i=1;i<10;i++)
	{
		if(i==4) continue;
		for(int j=0;j<10;j++)
		{
			if(j==4) continue;
			for(int v=0;v<10;v++)
			{
				if(v==4)continue;
				for(int k=0;k<10;k++)
				{
					if(k==4) continue;
					for(int m=0;m<10;m++)
					{
						if(m==4) continue;
						count++;
					//	printf("%d %d %d %d %d\n",i,j,v,k,m);
					}
				}
			}
		}
	} 
	printf("%d",count);
}

