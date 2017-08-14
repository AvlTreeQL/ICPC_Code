#include<stdio.h>
#include<string.h>
void fun2(char *a,int b);
void fun(char *a);
int main()
{
	char a[200];
	void fun(char *a);
	while(~scanf("%s",a))
	{
		fun(a);
		puts(a);
	}
	return 0;
}
void fun(char *a)
{
	int i,b=0;
	char max=a[0];
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			b=i;
		}
	}
	for(i=0;a[i]!='\0';i++)
		if(a[i]==a[b])
		{
			fun2(a,i);
			i=i+5;
		}
}
void fun2(char *a,int b)
{
	char c[200];
	int i;
	strcpy(c,a);
	a[b+1]='(';
	a[b+2]='m';
	a[b+3]='a';
	a[b+4]='x';
	a[b+5]=')';
	for(i=b+1;c[i]!='\0';i++)
		a[b+++6]=c[i];
	a[b+6]='\0';
}
/*
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。 
Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。 
Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。 
Sample Input
abcdefgfedcba
xxxxx
Sample Output
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)
*/