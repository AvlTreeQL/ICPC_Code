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