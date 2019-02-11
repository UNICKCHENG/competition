/**
 * 生日蜡烛
 * 签到题目。暴力足以。
 * 26
*/
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    for(int x=1;x<200;++x)
    {
        for(int y=x;y<200;++y)
        {
            int tmp=(x+y)*(y-x+1);
            if(tmp>472) break;
            if(tmp==472) cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}