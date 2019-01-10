#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  
int flag_node(int *p, int high, int low)
{
    if (p[1] < low || p[2] < low)
        return 0;          // 第五类
    else if (p[1] >= high && p[2] >= high)
        return 4;          // 第一类
    else if (p[1] >= high)
        return 3;          // 第二类
    else if (p[2] <= p[1])
        return 2;          // 第三类
    else
        return 1;          // 第四类
}
  
int comp(const void *a_t, const void *b_t)
{
    int *a = (int*)a_t, *b = (int*)b_t;
    int sum1 = a[1]+a[2], sum2 = b[1]+b[2];
  
    if (sum1 != sum2)      return sum2 - sum1; // 按总分排序 
    else if (a[1] != b[1]) return b[1] - a[1]; // 总分相等时按德分排序
    else                   return a[0] - b[0]; // 德分相等时按学号排序
}
  
int main()
{
    int low, high, n, cs, tmp[3], cn[4] = {0};
    scanf("%d %d %d", &n, &low, &high);
    int a[4][n][3];
  
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", tmp, tmp+1, tmp+2);
        cs = flag_node(tmp, high, low); // 按题目要求分类
        if (cs) memcpy(a[cs-1][cn[cs-1]++], tmp, 3*sizeof(int)); //只记录前四类有用的数据
    }
  
    printf("%d\n", cn[0]+cn[1]+cn[2]+cn[3]); // 输出记录数据的份数
    for (int i = 3; i >= 0; i--) {
        qsort(a[i], cn[i], 3*sizeof(int), comp); // 对每一类排序
        for (int j = 0; j < cn[i]; j++) // 排序后直接输出
            printf("%d %d %d\n", a[i][j][0], a[i][j][1], a[i][j][2]);
    }
  
    return 0;
}
