/**
 * 1049 Counting Ones（30 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456
 * 题目大意:给一个数字N,输出1~N的全部数字中1出现的总次数
 * 解题思路:把一个数字拆成三部分,right(0+位),now(1位),left(0+位),a为now在数字N中的位置,个位则为1,十位为10,百位为100...
 *         若now==0,将只有left决定,因为其变换有(0~left-1),故ans+=left*a;
 *         若now==1,表示在left位在(0~left-1)变换下,还有now=1后面的right+1个1,所以ans += left * a + right + 1;
 *         若now>=2,将只有left决定,因为其变换有(0~left),故ans+=(left+1)*a;
 */
#include<cstdio>
#include <iostream>
using namespace std;
// zhicheng
// August 26,2018
int main() 
{
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) 
    {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d\n", ans);
    return 0;
}
