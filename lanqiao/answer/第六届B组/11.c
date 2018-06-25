#include<stdio.h>
#define Max 1000
int number;
int data[Max];
int num0=0,num1=0,num2=0,num4=0;
double num3=0;
/*-----------------------------------------------------*/
void fun0(int num)//能被5整除的数字中所有偶数的和
{
    if(!num%2) num0+=num;
}
void fun1(int num)//将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...
{
    static int count_fun1=1;
    if(!count_fun1%2) num1-=num;
    else         num1+=num;
    count_fun1++;
}
void fun2()//被5除后余2的数字的个数
{
    num2++;
}
void fun3(int num)//被5除后余3的数字的平均数，精确到小数点后1位
{
    static int count_fun3=0;
    static int numb_fun3=0;
    count_fun3++;//个数
    numb_fun3+=num;//总数和
    num3=numb_fun3*1.0/count_fun3;
}
void fun4(int num)//被5除后余4的数字中最大数字
{
    if(num4<num) num4=num;
}
/*-----------------------------------------*/
int main()
{
    int select;
    scanf("%d",&number);
    //初始化
    for(int i=0;i<number;i++)
    {
        scanf("%d",&data[i]);
    }
    //对每组数据进行分类处理
    for(int i=0;i<number;i++)
    {
        select=data[i]%5;
        switch(select)
        {
            case 0:fun0(data[i]);break;
            case 1:fun1(data[i]);break;
            case 2:fun2();break;
            case 3:fun3(data[i]);break;
            case 4:fun4(data[i]);break;
        }
    }
    //输出结果
    if(!num0) printf("N ");
    else      printf("%d ",num0);
    if(!num1) printf("N ");
    else      printf("%d ",num1);
    if(!num2) printf("N ");
    else      printf("%d ",num2);
    if(!num3) printf("N ");
    else      printf("%.1f ",num3);
    if(!num4) printf("N ");
    else      printf("%d ",num4);
    return 0;
}
