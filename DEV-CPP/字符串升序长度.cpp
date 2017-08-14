#include<stdio.h>
#include<string.h>
int fun(char *a);
int main()
{
	int n,i;
	char a[100][80];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a[i]);
	}
	for(i=0;i<n;i++)
		printf("%d\n",fun(a[i]));
	return 0;
}
int fun(char *a)
{
	int n=1,i,j,max=0;
	for(i=0;a[i]!='\0';i++)
	{
		for(j=i+1,n=1;a[j]!='\0';j++)
		{
			if(a[j]>a[i]) n++;
			else break;
		}
		if(n>max) max=n;
	}
	return max;
}
/*
4、字符串
问题描述：
对于给定字符串，计算字符串中最大升序长度。
例如字符串：BEBACD，
以第1个字符B开头的升序序列为BE，其长度为2；
以第2个字符E开头的升序序列为E，其长度为1；
以第3个字符B开头的升序序列为BCD，其长度为3；
以第4个字符A开头的升序序列为ACD，其长度为3；
以第5个字符C开头的升序序列为CD，其长度为2；
以第6个字符D开头的升序序列为D，其长度为1；
输入数据：
第一行一个整数m表示测试数据的组数。接下来m行，每行有为一个长度小于80的字符串，字符串均为大写字母。
输出数据:
输出一个整数，字符串中最大升序长度。
输入样例 
2
BEBACD 
SSSSS
输出样例
3
1
*/