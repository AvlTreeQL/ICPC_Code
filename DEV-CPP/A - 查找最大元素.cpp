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
���������ÿ���ַ������������е������ĸ���ڸ���ĸ��������ַ�����(max)���� 
Input
�������ݰ����������ʵ����ÿ��ʵ����һ�г��Ȳ�����100���ַ�����ɣ��ַ������ɴ�Сд��ĸ���ɡ� 
Output
����ÿ������ʵ�����һ���ַ���������Ľ���ǲ����ַ�����(max)����Ľ����������ڶ��������ĸ������ÿһ�������ĸ���涼����"(max)"�� 
Sample Input
abcdefgfedcba
xxxxx
Sample Output
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)
*/