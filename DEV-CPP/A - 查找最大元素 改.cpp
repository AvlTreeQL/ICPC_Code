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
#include<stdio.h>
#include<string.h>
void stick(char a[100],char b[20],char *p);
int main()
{
	char a[100],max;
	int i;
	while(~scanf("%s",a))
	{
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]>=max) max=a[i];
		}
		for(i=0;a[i]!='\0';i++)
			if(a[i]==max) stick(a,"(max)",&a[i]),i+=5;
		
		puts(a);
	}
	
	return 0;
}
void stick(char a[100],char b[20],char *p)
{
	char t1[100],t2[100];
	strcpy(t2,p+1);
	*(p+1)='\0';
	strcpy(t1,a);
	strcat(t1,b);
	strcat(t1,t2);
	strcpy(a,t1);
}