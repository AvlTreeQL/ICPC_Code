#include<stdio.h>
int main()
{
	int n;
	char a[50],b[50];
	void copy(char *a,char *b,int n);
	gets(a);
	scanf("%d",&n);
	copy(a,b,n);
	puts(b);
	return 0;
}
void copy(char *a,char *b,int n)
{
	int i;
	for(i=n-1;*(a+i)!='\0';i++)
	{
		*(b++)=*(a+i);
	}
	*b='\0';
}
/*
问题描述
有一字符串，包含n个字符。写一函数，用指针方法实现将此字符串中从第m个字符开始的全部字符复制成为另一个字符串，其中m小于n。
输入形式
输入两行，第一行是一个字符串，第二行是正整数m。
输出形式
输出一行，给出满足条件复制后的字符串。
样例输入
You are a student.
5
样例输出
are a student.
*/