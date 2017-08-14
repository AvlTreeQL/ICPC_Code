#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
		while(a%i==0) //while(a%i==0)
			if(a%i==0) 
			{
				a=a/i;
				printf("%d ",i);
			}
	return 0;
}

/*	
问题描述
给定一个正整数a，分解质因数。例如：输入90，输出90=2*3*3*5。
输入形式
输入一行，只包括个正整数a，a大于1。
输出形式
输出一行，给出一个正整数a分解的质因数，各个质因数之间的空格分隔。
样例输入
90
样例输出
       2 3 3 5
*/