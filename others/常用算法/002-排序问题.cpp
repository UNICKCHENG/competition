#include<iostream>
using namespace std;

/*--------------------归并排序----------------------------------------------*/
void mergesort(int* a,int l,int r,int* b)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(a,l,mid,b);
	mergesort(a,mid+1,r,b);
	int i=l,k=l,j=mid+1;
	while(i<=mid&&j<=r)		//将i-mid和j-r两组有序序列，归并在一个有序序列中
	{
		if(a[i]<=a[j]) b[k++]=a[i++];
		else  b[k++]=a[j++];
	}
	while(i<=mid) b[k++]=a[i++];		//将i-mid剩余的数放在最后
	while(j<=r) b[k++]=a[j++];		//将j-r剩余的数放在最后
	for(k=l;k<=r;k++) a[k]=b[k]; 		//将b数组中的数据拷贝到原数组中
}
/*--------------------归并排序----------------------------------------------*/

/*--------------------快速排序----------------------------------------------*/
void quicksort(int* a,int l,int r)
{
	if(l>=r) return;
	int temp=a[l];//哨兵
	int i=l,j=r;
	while(i<j)
	{
		while(i<j)//自右向左判断
		{
			if(a[j]>=temp) j--;
			else{a[i++]=a[j];break;}
		}
		while(i<j)//自左向右判断
		{
			if(a[i]<=temp) i++;
			else{a[j--]=a[i];break;}
		}
	}
	a[i]=temp;//将哨兵放回中间位置
	quicksort(a,l,i-1);
	quicksort(a,i+1,r);
}
/*--------------------快速排序----------------------------------------------*/


int main()
{
	int a1[]={8,4,5,7,1,3,6,2};
	int a2[]={8,4,5,7,1,3,6,2};
	// int a3[]={8,4,5,7,1,3,6,2};
	int size=sizeof(a1)/sizeof(int);
	int b[size];

	cout<<"#初始状态："<<"\n";
	for(int i=0;i<size;i++) cout<<a1[i]<<" ";
	cout<<"\n";

/*归并排序*/
	mergesort(a1,0,size-1,b);//归并排序
	cout<<"#归并排序："<<"\n";
	for(int i=0;i<size;i++) cout<<a1[i]<<" ";
	cout<<"\n";

/*快速排序*/
	quicksort(a2,0,size-1);
	cout<<"#快速排序："<<"\n";
	for(int i=0;i<size;i++) cout<<a2[i]<<" ";
	cout<<"\n";
	return 0;
}