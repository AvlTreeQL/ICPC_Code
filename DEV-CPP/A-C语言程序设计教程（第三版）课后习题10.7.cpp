/*
��Ŀ����
��һ�ַ���������n���ַ���дһ�����������ַ����дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ�����
����
����n һ���ַ��� ����m
���
��m��ʼ���Ӵ�
��������
6
abcdef
3
�������
cdef
*/
#include<stdio.h>
int main()
{
	int n;
	char a[200];
	scanf("%d",&n);
	getchar();
	gets(a);
	scanf("%d",&n);
	puts(a+n-1);
	return 0;
}