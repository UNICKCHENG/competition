/*
	给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
	
	输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
	输出格式：每个测试用例的输出占一行，输出倒序后的句子。
	
	输入样例：
	Hello World Here I Come
	输出样例：
	Come I Here World Hello
*/

//zhicheng
//Mar 7,2018
//方法1：strtok切割思想--------------------------------------------------------- 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
	char str[80];
	const char *ch = " ";
	char *result;
	vector<char *> v;
	gets(str);//注意用的是gets()可以连带空格都扫描进去

	result = strtok(str,ch);
	while(result!=NULL)
	{
		v.push_back(result);
		result = strtok(NULL,ch);
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		if(i!=0)
			cout<<v[i]<<" ";
		else
			cout<<v[i];
	}
	return 0;	
}
/*
//方法2：栈的思想--------------------------------------------------------------- 
#include <iostream>  
#include <stack>  
#include <string>  
using namespace std;  
int main()  
{  
    stack<string> s;  
    string  sp;  
    bool flag=false;  
    while(cin>>sp)  
        s.push(sp);  
      
    while(!s.empty())  
    {  
        if(flag)  
            cout<<" ";  
        else  
            flag=true;  
        cout<<s.top();  
        s.pop();  
      
    }  
    return 0;  
}  
*/

