/**
 * 凑算式
 * 29
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
int main()
{
    int ans=0;
    int a[9]={1,2,3,4,5,6,7,8,9};
    do{
        int x=a[3]*100+a[4]*10+a[5];
        int y=a[6]*100+a[7]*10+a[8];
        if(a[0]*a[2]*y+a[1]*y+a[2]*x==10*a[2]*y)
        {
            ans++;
            for(int i=0;i<9;i++) printf("%d ",a[i]);
            printf("\n");
        }
    }while(next_permutation(a,a+9));
    printf("%d\n",ans);
    return 0;
}