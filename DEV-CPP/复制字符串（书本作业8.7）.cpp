#include<stdio.h>
int main()
{
	int n;
	char a[50],b[50];
	void copy(char *a,char *b,int n);
	gets(a);
	scanf("%d",&n);
	copy(a,b,n);
	puts(b);
	return 0;
}
void copy(char *a,char *b,int n)
{
	int i;
	for(i=n-1;*(a+i)!='\0';i++)
	{
		*(b++)=*(a+i);
	}
	*b='\0';
}
/*
��������
��һ�ַ���������n���ַ���дһ��������ָ�뷽��ʵ�ֽ����ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ���������mС��n��
������ʽ
�������У���һ����һ���ַ������ڶ�����������m��
�����ʽ
���һ�У����������������ƺ���ַ�����
��������
You are a student.
5
�������
are a student.
*/