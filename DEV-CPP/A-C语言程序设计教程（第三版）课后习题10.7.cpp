/*
题目描述
有一字符串，包含n个字符。写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
输入
数字n 一行字符串 数字m
输出
从m开始的子串
样例输入
6
abcdef
3
样例输出
cdef
*/
#include<stdio.h>
int main()
{
	int n;
	char a[200];
	scanf("%d",&n);
	getchar();
	gets(a);
	scanf("%d",&n);
	puts(a+n-1);
	return 0;
}