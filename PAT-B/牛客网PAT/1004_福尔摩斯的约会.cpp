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



// --- the older code
// It will be accepted by the data of nowcoder,but not so in PTA.
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
//zhicheng
//Jun.24,2018

string ww[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

void com1(string s1,string s2,int& w,int& h)
{
		int first=1;
		int i=0;
		do
		{
			// 找第1对相同的大写英文字母
			if(first==1&&s1[i]>='A'&&s1[i]<='Z'&&s2[i]>='A'&&s2[i]<='Z')
			{
				if(s1[i]==s2[i]) w=s1[i]-'A'+1;
				first=2;
				i++;
				//continue;
			}
			// 第2对相同的字符
			if(first==2&&s1[i]==s2[i])
			{
				if(s1[i]>='0'&&s1[i]<='9') {h=s1[i]-'0';break;}
				else if(s1[i]>='a'&&s1[i]<='z'||s1[i]>='A'&&s1[i]<='Z')
				{
					char te=s1[i];
					te=tolower(te);
					h=te-'a'+10;
					break;
				}
			}
			i++;
		}while(s1[i]!='\0'&&s2[i]!='\0');
}
void com2(string s3,string s4,int& m)
{
	int i=0;
	do
	{
		if(s3[i]==s4[i])
		{
			if(s3[i]>='a'&&s3[i]<='z'||s3[i]>='A'&&s3[i]<='Z')
			{
				m=i;
				break;
			}	
		}
		i++;
	}while(s3[i]!='\0'&&s4[i]!='\0');
}

int main()
{
	string s1,s2,s3,s4;
	freopen("1.txt","r",stdin);
	while(cin>>s1>>s2>>s3>>s4)
	{
		int week,hour,minu;
		week=hour=minu=0;
		com1(s1,s2,week,hour);
		com2(s3,s4,minu);
		//考虑到周期性且字符串最长不会超过60
		week=week%7;
		if(hour>=24){week+=hour/24;hour=hour%24;}
		if(minu>=60) {minu=minu%60;hour++;}
		//cout<<ww[week]<<" "<<hour<<" "<<minu<<endl;
		cout<<ww[week];
		printf(" %02d:%02d\n",hour,minu);
	}
	return 0;
}