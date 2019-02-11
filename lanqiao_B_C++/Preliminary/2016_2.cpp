/**
 * 26
*/
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int ans=236;
    for(int x=1;x<=200;x++)
    {
        for(int y=x;y<=200;y++)
        {
            if((x+y)*(y-x+1)==472)
            {
                printf("%d\n",x);
            }
        }
    }
    return 0;
}