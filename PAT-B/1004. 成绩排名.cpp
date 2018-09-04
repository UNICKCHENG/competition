/**
	读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
	输入格式：每个测试输入包含1个测试用例，格式为
	  第1行：正整数n
	  第2行：第1个学生的姓名 学号 成绩
	  第3行：第2个学生的姓名 学号 成绩
	  ... ... ...
	  第n+1行：第n个学生的姓名 学号 成绩
	其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
	
	输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
	输入样例：
	3
	Joe Math990112 89
	Mike CS991301 100
	Mary EE990830 95
	输出样例：
	Mike CS991301
	Joe Math990112
*/
//zhicheng
//Mar.5,2018  22 min

#include<cstdio>
#include<iostream>
#include<iostream>
/*ends实际上是输出了一个'\0'字符，并不是我们想象的空格。*/
using namespace std; 

typedef struct student
{
	string name;
	string numb;
	int score;
}student;

int main()
{
	int n;
	while(cin>>n)
	{
		student stu[n];
		int cnt1,cnt2;
		int max=0,min=101;
		//input the information of student 
		for(int i=0;i<n;i++)
		{
			cin>>stu[i].name>>stu[i].numb>>stu[i].score;
		}
		//sorting and screening
		for(int i=0;i<n;i++)
		{
			if(stu[i].score<min){ min=stu[i].score;cnt1=i;}
			if(stu[i].score>max){max=stu[i].score;cnt2=i;}
		}
		//output
		cout<<stu[cnt2].name<<" "<<stu[cnt2].numb<<endl;
		cout<<stu[cnt1].name<<" "<<stu[cnt1].numb<<endl;
	}
	return 0;
}
