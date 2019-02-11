#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=105;

int solve(char* s)
{
    int a[maxn];// 表示栈
    int top=0;// 表示栈顶指针
    memset(a,0,sizeof(a));
    for(int i=0,len=strlen(s);i<len;++i)
    {
        switch(s[i])
        {
            case '(': 
                break;
            case '|':
                ++top;
                break;
            case ')':
                a[top-1]=max(a[top],a[top-1]);
                a[top]=0;// 清空栈顶数据
                --top;// 栈顶指针下移一格
                break;
            default:
                ++a[top];
                break;
        }
    }
    // 题目描述不清楚，以防出现类似 xx|x 这样的形式
    while(top!=0)
    {
        a[top-1]=max(a[top],a[top-1]);
        --top;
    }
    return a[0];
}

int main()
{
    char str[maxn];
    scanf("%s",str);
    cout<<solve(str)<<endl;
    return 0;
}