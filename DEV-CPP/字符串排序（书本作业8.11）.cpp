#include<stdio.h>
#include<string.h>
void swap(char *a,char *b);
void sort(char a[80][80],int n);
int main()
{
	int n,i;
	char a[80][80];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
		gets(a[i]);
	sort(a,n);
	for(i=0;i<n;i++)
		puts(a[i]);
	return 0;
}
void sort(char a[80][80],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(strcmp(a[j],a[j+1])>0)
				swap(a[j],a[j+1]);
}
void swap(char *a,char *b)
{
	char c[80];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}
/*
��������
��������������n�����ַ���������һ������ָ�뷽�������ǰ���ASCII���С�����˳������Ȼ���������������n�����ź�����ַ�������n������10��ÿ���ַ����ĳ��Ȳ�����80��
������ʽ
����n+1�У���һ����������n���ڶ��е���n+1����n���ַ�����
�����ʽ
���n�У���������õ�n���ַ�����
��������
5
Bbbb b
Aaaa a
Ccccc c
Eeeee e
Ddddd
�������
Aaaa a
Bbbb b
Ccccc c
Ddddd
Eeeee e
*/