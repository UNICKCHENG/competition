#include<stdio.h>

int main()
{
	int num1,num2,result;
	int a,b,c,d,e,f,g,h,i;
	for(num1=1000;num1<9999;num1++)
		for(num2=1000;num2<9999;num2++)
		{
			a=num1/1000;
			b=num1/100%10;
			c=num1/10%10;
			d=num1%10;
			e=num2/1000;
			f=num2/100%10;
			g=num2/10%10;
			h=num2%10;
			if(b!=h||a==b||a==c||a==d||a==e||a==f||a==g||b==c||b==d||b==e||b==f||b==g||c==d||c==e||c==f||c==g||d==e||d==f||d==g||e==f||e==g||f==g) continue;//两个数字共同部分 
			result=num1+num2;
			if(result<10000) continue;//结果位两位数 
			i=result%10;
			if(i==a||i==b||i==c||i==d||i==e||i==f||i==g) continue;
			if(((result/10000)==(num2/1000))&&((result/1000)%10)==((num2/100)%10)&&((result/100)%10)==((num1/10)%10)&&((result/10)%10)==(num2%10))
				printf("%d+%d=%d\n",num1,num2,result);
		}
	return 0;
}
