/**
 * 1019 General Palindromic Number (20)（20 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984
 * https://www.nowcoder.com/pat/1/problem/4010
 */
#include<cstdio>
//zhicheng
//Aug.4,2018
inline void getHex(int n,int b,int* re,int& tot)
{
	if(n==0) {re[tot++]=0;return;}
	while(n) {re[tot++]=n%b;n/=b;}
}
inline bool is_Test(int re[],int tot)
{
	for(int i=0,j=tot-1;i<=j;i++,j--)
		if(re[i]!=re[j]) return false; 
	return true;
}
int main()
{
	int n,b,re[32],tot=0;
	scanf("%d %d",&n,&b);
	getHex(n,b,re,tot);
	if(is_Test(re,tot)) printf("Yes\n");
	else printf("No\n");
	for(int i=tot-1;i>=0;i--)
	{
		printf("%d",re[i]);
		if(i) printf(" ");
	}
	printf("\n");
	return 0;
}
