#include<stdio.h>
int main()
{
	char a[50],b[50],*t=a,*p=b;
	void fun(char *p,char *t);
	gets(a);
	fun(t,p);
	puts(b);

	return 0;
}
void fun(char *t,char *p)
{
	for(;*t!='\0';t++)
	if(*t=='A'||*t=='E'||*t=='I'||*t=='O'||*t=='U'||*t=='a'||*t=='e'||*t=='i'||*t=='o'||*t=='u')
	{
		*(p++)=*t;
	}
	*p='\0';
}
/*
	
��������
дһ��������һ���ַ����е�Ԫ����ĸ���Ƶ���һ�ַ������������������������ַ�����
������ʽ
����һ�У�����һ���ַ�����
�����ʽ
���һ�У�������ƺ���ַ�����
��������
I am a student.
�������
Iaaue
*/