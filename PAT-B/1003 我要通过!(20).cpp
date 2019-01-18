/**
 * title: 1003 我要通过!(20)
 * links: https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192
 * 解题思路: 规律题。无聊的找规律。
 *          条件2很容易明白，xPATx满足对称性，那么用对称判断下便可以了
 *          条件3说的比较含糊，因为需要结合条件2看，aPbTc很像条件2的xPATx,其实aPbTc的基本式就是xPATx，可自行证明
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
// zhicheng
//January,18,2019
bool scan(char* a,int& p,int& t)
{
    int len=strlen(a);
    if(len<3) return false;// 主要用于剔除 PT
    for(int i=0;i<len;i++)
    {
        switch(a[i])
        {
            case 'A':break;// 遇到A跳过
            case 'P':// 遇到 P，记录P的位置，如果之前已经存在P了，说明该字符串不满足要求，直接返回
                if(p==-1) p=i;
                else return false;
                break;
            case 'T':// 同 P
                if(t==-1) t=i;
                else return false;
                break;
            default:// 出现其他非法字符
                return false;
        }
    }
    return true;
}
int main()
{
    // freopen("1.in","r",stdin);
    int n;char a[105];
    for(scanf("%d",&n);n;n--)
    {
        int p=-1,t=-1;// 记录p和t在字符串中的位置下标
        scanf("%s",a);
        // 粗步划分
        if(scan(a,p,t)==false) 
        {// 说明里面存在非法字符，或者P和T出现多次,或者长度不足三位
            printf("NO\n");
            continue;
        }
        // 精确划分
        else
        {
            int len=strlen(a);
            if(t-p==2&&len-1-t==p) printf("YES\n");// xPATx模式
            else if(p*(t-p-1)==len-1-t) printf("YES\n");// aPbTc模式
            else printf("NO\n"); 
        }
    }
    return 0;
}