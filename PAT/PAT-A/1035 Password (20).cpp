/**
 * 1035 Password (20)（20 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520
 * 题目大意：给定用户名和密码，判断密码是否合乎标准，若如不符，则需要将其转换成对应的标准形式，并输出
 * 解题思路：字符串处理。对密码进行遍历，若如发现需要更换的字符，将其换成对应的标准形式并记录下结果
 */
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
// zhicheng
// August 17,2018
vector<string> re;
int main()
{
    // freopen("1.in","r",stdin);
    int t,count=0,numb;
    for(scanf("%d",&t),numb=t;t;t--)
    {
        int cnt=0;bool flg=false;
        string id,pw; cin>>id>>pw;//输入用户名和密码
        while(pw[cnt]!='\0') 
        {
            switch(pw[cnt])
            {// 如若出现以下字符，将其转换成对应的标准形式
                case '1': pw[cnt]='@';flg=true;break;
                case '0': pw[cnt]='%';flg=true;break;
                case 'l': pw[cnt]='L';flg=true;break;
                case 'O': pw[cnt]='o';flg=true;break;
            }
            cnt++;
        }
        if(flg) {count++;re.push_back(id+" "+pw);}//如若本次密码存在不符，记录下用户名和修改后的密码
    }
    if(count==0)
        if(numb<=1) printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n",numb);
    else{
        printf("%d\n",count);
        for(int i=0;i<count;i++)
            printf("%s\n",re[i].c_str());
    } 
    re.clear();
    return 0;
}
