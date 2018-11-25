/**
 * 1088 Rational Arithmetic(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520
 * 题目大意：求分数的四则运算，并按其格式输出
 * 解题思路：暴力计算
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// November,14,2018
long int gcd(long int a,long int b){return b==0?a:gcd(b,a%b);}
inline void hujian(long int& a,long int& b)
{
    long int tmp=gcd(a,b);
    if(tmp<0) tmp=-tmp;
    a/=tmp;b/=tmp;
}
inline void print(long int a,long int b)
{// 分数的输出格式
    if(a==0) {printf("0");return;}
    bool flg=true;
    if(a<0) {flg=false;a=-a;}
    if(flg==false) printf("(-");
    if(a>=b) 
    {
        long int tmp=a/b;a-=tmp*b;
        printf("%ld",tmp);
        if(a) printf(" %ld/%ld",a,b);
    }
    else 
    {
        printf("%ld/%ld",a,b);
    }
    if(flg==false) printf(")");
}
inline void fun1(long int a,long int b,long int c,long int d,long int& ra,long int& rb)
{// 加法
    ra= a*d+b*c; rb=b*d;
    hujian(ra,rb);
    print(a,b);printf(" + ");print(c,d);printf(" = ");print(ra,rb);
}
inline void fun2(long int a,long int b,long int c,long int d,long int& ra,long int& rb)
{// 减法
    ra=a*d-b*c;rb=b*d;
    hujian(ra,rb);
    print(a,b);printf(" - ");print(c,d);printf(" = ");print(ra,rb);
}
inline void fun3(long int a,long int b,long int c,long int d,long int& ra,long int& rb)
{// 乘法
    ra=a*c;rb=b*d;
    hujian(ra,rb);
    print(a,b);printf(" * ");print(c,d);printf(" = ");print(ra,rb);
}
inline void fun4(long int a,long int b,long int c,long int d,long int& ra,long int& rb)
{// 除法
    print(a,b);printf(" / ");print(c,d);printf(" = ");
    if(c==0) {printf("Inf");return ;}
    ra=a*d;rb=b*c;
    if(rb<0) {rb=-rb;ra=-ra;}
    hujian(ra,rb);
    print(ra,rb);
}

int main()
{
    // freopen("2.in","r",stdin);
    long int a,b,c,d,ra,rb;
    scanf("%ld/%ld %ld/%ld",&a,&b,&c,&d);
    hujian(a,b);hujian(c,d);
    fun1(a,b,c,d,ra,rb);printf("\n");
    fun2(a,b,c,d,ra,rb);printf("\n");
    fun3(a,b,c,d,ra,rb);printf("\n");
    fun4(a,b,c,d,ra,rb);printf("\n");
    return 0;
}