#include<stdio.h>
#include<stdlib.h>

/*------------------------------------------------------------------------------
全局变量：
		map[12}：存储原图中各点信息
		data_poor[4]：剪切后数据之间相差值 
		visit[5]:剪切后各点数据是否遍历的判断条件，0为未遍历
		count：计算满足题目条件的情况次数 
------------------------------------------------------------------------------*/
int map[12]={1,2,3,4,6,7,8,9,11,12,13,14};
int data_poor[4]={-1,1,-5,5};
int visit[5]={0},count=0; 
int data[5];//存放剪切后的数据 
int flag=0;//满足条件标志为1，否则为0； 
//int data_function(int n); 
/*------------------------------------------------------------------------------

------------------------------------------------------------------------------*/
int main()
{
	for(int num1=0;num1<12;num1++)
		for(int num2=num1+1;num2<12;num2++)
			for(int num3=num2+1;num3<12;num3++)
				for(int num4=num3+1;num4<12;num4++)
					for(int num5=num4+1;num5<12;num5++)
					{
						data[0]=map[num1];
						data[1]=map[num2];
						data[2]=map[num3];
						data[3]=map[num4];
						data[4]=map[num5];
						/*对各个点遍历初始化，为0*/
						for(int i=0;i<5;i++) 
						{
							visit[i]=0;
						}
						visit[0]=1;
						/*对是否满足题目要求的flag初始化，为0*/
						flag=0;
						
						flag=data_function(0);//对数据进行判断 
						
						if(!flag) continue;
						count++;
					} 
	printf("%d",count);//输出满足题目条件的情况次数 
} 


/*------------------------------------------------------------------------------
data_function(int n):深度遍历 
------------------------------------------------------------------------------*/
int data_function(int n)
{
	int compare;//数据加上数据之间的相差值，用于匹配后面相同值的数据 
	for(int i=0;i<4;i++)
	{
		compare=data[n]+data_poor[i];
		/*排除特殊情况*/
		if(compare<1||compare>14||compare==5||compare==10) continue;
		/*在未遍历的数据之间进行匹配，匹配成功，则遍历成功，即该点遍历条件为1*/
		for(int v=0;v<5;v++)
		{
			if(!visit[v]&&compare==data[v])
			{
				visit[v]=1;
				data_function(v);//进行深度遍历 
			} 
		} 
	} 
	
	//判断遍历过程是否结束，即是否返回至根部 
	if(!n)
	{
		/*查询是否都已经遍历，否则表示该数据不满足条件，返回flag*/
		for(int k=0;k<5;k++)
		{
			if(!visit[k]) return flag;
		} 
		flag=1;
		return flag;	
	} 
} 


 
