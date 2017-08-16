/*
Given a positive integer n, write a program to find out a nonzero multiple m of n whose decimal representation contains only the digits 0 and 1. You may assume that n is not greater than 200 and there is a corresponding m containing no more than 100 decimal digits.
Input
The input file may contain multiple test cases. Each line contains a value of n (1 <= n <= 200). A line containing a zero terminates the input.
Output
For each value of n in the input print a line containing the corresponding value of m. The decimal representation of m must not contain more than 100 digits. If there are multiple solutions for a given value of n, any one of them is acceptable.
Sample Input
2
6
19
0
Sample Output
10
100100100100100100
111111111111111111
给定一个正整数n，写一个程序来找出一个非零多M的n，其十进制表示只包含数字0和1。您可以假设n不大于200，并且对应的m包含不超过100个十进制数字。
输入
输入文件可能包含多个测试用例。每行包含n值（1 < n = n = 200）。一行包含一零终止输入。
输出
对于输入中n的每个值，打印一个包含相应值m的行。m的十进制表示不能包含100位数以上。如果有n个给定值的多个解，任何一个都可以接受。

Sample Input
2
6
19
0
Sample Output
10
100100100100100100
111111111111111111
*/
#include<iostream>
#include<sstream>
using namespace std;
bool flag;
void DFS(unsigned long long x,int n)
{
	if(flag==true||x>=10000000000000000000) return ;
	if(x%n==0)
	{
		cout<<x<<endl;
		flag=true;
		return ;
	}
	DFS(x*10,n);
	DFS(x*10+1,n);	
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)break;
		flag=false;
		DFS(1,n);
	}
	
	return 0;
}