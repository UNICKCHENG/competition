/**
 * swap(a,p,j);
*/
#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1){
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
    swap(a,p,j);
	//______________________;
    return j;
}

void quicksort(int a[], int p, int r)
{
    if(p<r){
        int q = partition(a,p,r);// 将所有元素和哨兵比较，获得更新后的哨兵位置，要求左边的值比哨兵小，右边的值比哨兵大
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
    
int main()
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	
	quicksort(a, 0, N-1);// 快排模块，a代表待排序列，0和n-1分别代表序列最左边和最右边的下标
	
	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
