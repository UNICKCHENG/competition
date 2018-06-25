#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int LIS(int *a,int n){
         int *dp=new int[n];         //存储以i为尾的最长上升子序列长度
         int mx=0,m,i,j;
         dp[0]=1;                            //初值，第一个字符为1
         for(i=1;i<n;i++){
                  m=0;
                  for(j=0;j<i;j++){        //对当前i之前的所有元素的最长上升子序列做判断
                          if(dp[j]>m&&a[j]<a[i]){
                                   m=dp[j];
                          }
                  }
                  dp[i]=m+1;               //最大m值再加上1
                  mx=max(mx,dp[i]); //同时判断所有最长上升子序列长度的最大值
         }
         return mx;
}

int main()
{
  int a[]={1,2,3,4,1,2,3,4,5,1,2,3,4,5,6,1,2,3,4,2};
  int n=sizeof(a)/sizeof(int);
  // cin>>ss;
  cout<<LIS(a,n)<<endl;
}