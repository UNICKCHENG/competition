/**
 * 消除尾一
 * 位运算
 * x=x&((x&1)?x+1:x);
*/
#include <stdio.h>

void f(int x)
{
    int i;
    for(i=0; i<32; i++) printf("%d", (x>>(31-i))&1);
    printf("   ");
    
    x=x&((x&1)?x+1:x);
    // x = _______________________;
    for(i=0; i<32; i++) printf("%d", (x>>(31-i))&1);
    printf("\n");    
}

int main()
{
    f(103);
    f(12);
    return 0;
}