#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

typedef struct matrix
{
    int row ; // 行
    int column; //列
    matrix(int r=0,int c=0):row(r),column(c){}
}D;
stack<D> st;
D d[27];

bool count(int& ans)
{
    D t2=st.top();st.pop();
    D t1=st.top();st.pop();
    if(t1.column!=t2.row) return true;
    st.push(D(t1.row,t2.column));
    ans+=t1.row*t1.column*t2.column;
    return false;
}

int main()
{
    // freopen("1.in","r",stdin);
    int n,ro,co;char c[2];
    for(scanf("%d",&n);n;n--)
    {
        scanf("%s %d %d",c,&ro,&co);
        d[c[0]-'A'].row=ro;d[c[0]-'A'].column=co;
    }
    string expr;
    while(cin>>expr)
    {
        int ans=0;bool error=false;
        for(int i=0,len=expr.length();error==false&&i<len;i++)
        {
            if(expr[i]=='(') continue;
            else if(expr[i]==')') error=count(ans);
            else st.push(d[expr[i]-'A']);
        }
        error==true?printf("error\n"):printf("%d\n",ans);
        while(!st.empty()) st.pop();
    }
    return 0;
}