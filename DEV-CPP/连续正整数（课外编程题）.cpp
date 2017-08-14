#include <stdio.h>
void fun(int n)
{
	int i,j,sum,m,flag=0;
	for(i=1;i<n;i++) 
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum+=j;
			if(sum>=n) break;
		}
		if(sum==n)
		{
			for(m=i;m<=j;m++)
				printf("%d ",m);
			printf("\n"); 
			flag=1; 
		} 
	} 
	if(flag==0) printf("NONE");
}
int main()
{ 
	int n; 
	scanf("%d",&n); 
	fun(n);
	return 0;
}
/*
【问题描述】
一个正整数有可能可以被表示为n(n>=2)个连续正整数之和，如： 
15=1+2+3+4+5 
15=4+5+6 
15=7+8 
请编写程序，根据输入的任何一个正整数，找出符合这种要求的所有连续正整数序列。
【输入形式】
从控制台输入一个正整数（小于等于10000）。
【输出形式】
在标准输出上输出符合题目描述的全部正整数序列，每行一个序列，每个序列都从该序列的最小正整数开始、以从小到大的顺序打印。如果结果有多个序列，按各序列的最小正整数的大小从小到大打印各序列。此外，序列不允许重复，序列内的整数用一个空格分隔，每个序列最后一个整数后要有一个空格。如果没有符合要求的序列，输出&ldquo;NONE&rdquo;。
【输入样例1】
15
【输出样例1】
1 2 3 4 5 
4 5 6 
7 8
【输入样例2】
16
【输出样例2】
NONE
【样例说明】
样例1输入的是15，其连续正整数序列有3个，分别输出。样例2输入的是16，没有连续的正整数序列之和为16，所以输出字符串：NONE。
【评分标准】
该题要求输出所有连续正整数序列，共有5个测试点，提交程序文件名为sum.c。
*/
