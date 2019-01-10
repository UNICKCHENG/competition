/**
 * title: 1152 Google Recruitment(20)
 * links:https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
 * 题目大意：从长度为L的整数中自左向右进行寻找，需要找到长度为L的一个整数，并且这个整数是素数，如果存在这样的数就把它输出，否则输出404
 * 解题思路：素数判定+字符串。
*/
#include <iostream>
#include <string>
using namespace std;
// zhicheng
// January,10,2018
bool isPrime(int n) 
{
    if(n<2) return false;
    for(int i=2;i<=n/i;i++) if(n%i==0) return false;
    return true;
}
int main() {
    int l,k;string s;
    cin>>l>>k>>s;
    for (int i=0;i<=l-k;i++) 
    {
        string t = s.substr(i, k);
        int num = stoi(t);
        if (isPrime(num)){cout<<t<<endl;return 0;}
    }
    cout << "404\n";
    return 0;
}