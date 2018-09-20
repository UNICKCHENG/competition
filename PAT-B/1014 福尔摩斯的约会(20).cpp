/**
 * 1004 福尔摩斯的约会(20)
 * nowcoder:https://www.nowcoder.com/pat/6/problem/4040
 * PTA: https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// September,20,2018
char* week[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    // freopen("1.in","r",stdin);
    char s1[61],s2[61],s3[61],s4[61];int w=-1,d=-1,m=-1;
    scanf("%s\n%s\n%s\n%s",s1,s2,s3,s4);
    for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++)// 匹配第一对字符串相关信息
        if(s1[i]==s2[i]){
            if(w==-1&&'A'<=s1[i]&&'N'>=s1[i]) w=s1[i]-'A';
            else if(w!=-1&&('0'<=s1[i]&&'9'>=s1[i])||('A'<=s1[i]&&'N'>=s1[i])){
                d=('0'<=s1[i]&&'9'>=s1[i])?s1[i]-'0':s1[i]-'A'+10;
                break;
            }
        }
    for(int i=0;s3[i]!='\0'&&s4[i]!='\0';i++)// 匹配第二对字符串相关信息
        if(s3[i]==s4[i])
            if(('A'<=s3[i]&&'Z'>=s3[i])||('a'<=s3[i]&&'z'>=s3[i])) {m=i;break;}
    printf("%s %02d:%02d\n",week[(w+(d+m/60)/24)%7],(d+m/60)%24,m%60);// 虽然字符串最长不超过60位,但仍需考虑进位问题
    return 0;
}
