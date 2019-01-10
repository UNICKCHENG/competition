#include<iostream>
using namespace std;

int f[5000];
int v[201],w[201];
 
int main() {
         int n=0,m,i,j,mx=0;
         cin>>n>>m;
         for(i=1;i<=n;i++){
                  cin>>w[i]>>v[i];
         }
         for(i=1;i<=n;i++){
                  for(j=m;j>=w[i];j--){
                          f[j]=max(f[j],f[j-w[i]]+v[i]);
                          mx=max(mx,f[j]);
                  }
         }
         cout<<mx;
         return 0;
}