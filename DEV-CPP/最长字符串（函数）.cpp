#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	void fun(char *p);
	gets(a);
	fun(a);
	return 0;
}
void fun(char *p)
{
	int a=0,b=1,max=0;
	char d[20],f[20];
	for(;*p!='\0';p++)
	{
		if(*p==' '||*p=='.')
		{
			b=0;		
		}
		else 
		{
			if(b==0)
			{	
				b=1;		
				a=0;
			}
			d[a++]=*p;
			if(a>max) 
			{
				max=a;
				f[a]=d[a]='\0';
				strcpy(f,d);
			}
		}
	}
	printf("%s",f);
}
/*
��������
дһ����������һ���ַ��������ַ�������ĵ���������������������������ַ�����
������ʽ
����һ�У�����һ��������80���ַ�����
�����ʽ
���һ�У�����ַ���������ʣ������������ͬ�ĵ��ʣ������һ�����ֵ��ʡ�
��������
There is a nice mouse.
�������
There
*/