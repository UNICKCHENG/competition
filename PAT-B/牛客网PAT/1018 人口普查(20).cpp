/**
 * 1018 人口普查(20)
 * https://www.nowcoder.com/pat/6/problem/4054
 */
//方法二
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.11,2018
int main()
{
	freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		string start="1814/09/06",end="2014/09/06";//合法日期的范围
		string maxn,minn,max_bir="1814/09/05",min_bir="2014/09/07";
		string name,bir;//要输入的变量
		int count=0;//记录合法日期的数量
		while(n--)
		{
			cin>>name>>bir;
			if(bir>=start&&bir<=end)
			{
				count++;
				if(bir>max_bir){max_bir=bir;minn=name;}
				if(bir<min_bir){min_bir=bir;maxn=name;}
			}
		}
		printf("%d %s %s\n",count,maxn.c_str(),minn.c_str());
	}
	return 0;
}

/*方法一
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		string maxn,minn;
		int max_bri[3]={1813},min_bri[3]={2015};
		string name;
		int bri[3];
		int count=0;
		while(n--)
		{
			cin>>name;
			scanf("%d/%d/%d",&bri[0],&bri[1],&bri[2]);
			if(bri[0]>1814||bri[0]==1814&&bri[1]>9||bri[0]==1814&&bri[1]==9&&bri[2]>=6)
				if(bri[0]<2014||bri[0]==2014&&bri[1]<9||bri[0]==2014&&bri[1]==9&&bri[2]<=6)
				{
					count++;
					if(max_bri[0]<bri[0]||max_bri[0]==bri[0]&&max_bri[1]<bri[1]||max_bri[0]==bri[0]&&max_bri[1]==bri[1]&&max_bri[0]<bri[0])
					{
						max_bri[0]=bri[0];max_bri[1]=bri[1];max_bri[2]=bri[2];
						maxn=name;
					}
					if(min_bri[0]>bri[0]||min_bri[0]==bri[0]&&min_bri[1]>bri[1]||min_bri[0]==bri[0]&&min_bri[1]==bri[1]&&min_bri[0]>bri[0])
					{
						min_bri[0]=bri[0];min_bri[1]=bri[1];min_bri[2]=bri[2];
						minn=name;
					}	
				}
		}
		printf("%d %s %s\n",count,minn.c_str(),maxn.c_str());
	}
	return 0;
}
*/