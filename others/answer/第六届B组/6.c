#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	int count=0;
	for(a=0;a<10;a++)
		for(b=0;b<10;b++)
		{
			if(a==b||abs(a-b)==1) continue;
			for(c=0;c<10;c++)
				{
					if(c==a||c==b||abs(b-c)==1) continue;
					for(d=0;d<10;d++)
					{	
						if(d==a||d==b||d==c||abs(a-d)==1) continue;
						for(e=0;e<10;e++)
						{
							if(e==a||e==b||e==c||e==d||abs(e-d)==1||abs(e-a)==1||abs(e-b)==1) continue;
							for(f=0;f<10;f++)
							{
								if(f==a||f==b||f==c||f==d||f==e||abs(f-e)==1||abs(f-a)==1||abs(f-b)==1||abs(f-c)==1) continue;
								for(g=0;g<10;g++)
								{
									if(g==a||g==b||g==c||g==d||g==e||g==f||abs(g-f)==1||abs(g-b)==1||abs(g-c)==1) continue;
									for(h=0;h<10;h++)
									{
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g||abs(h-d)==1||abs(h-e)==1) continue;
										for(i=0;i<10;i++)
										{
											if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h||abs(i-h)==1||abs(i-d)==1||abs(i-e)==1||abs(i-f)==1) continue;
											for(j=0;j<10;j++)
											{
												if(j==a||j==b||j==c||j==d||j==e||j==f||j==g||j==h||j==i||abs(j-i)==1||abs(j-e)==1||abs(j-f)==1||abs(j-g)==1) continue;
												//printf("%d %d %d %d %d %d %d %d %d %d\n\n",a,b,c,d,e,f,g,h,i,j);
												count++; 
											}
										}
									}
								}
							}
						}
					}
				}
		}
		printf("%d",count);
		return 0;
}
