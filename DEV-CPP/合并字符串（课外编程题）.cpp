/*
������������
��дһ������char * str_bin(char* str1, char* str2)�� str1��str2�����������ַ����������ַ���ASCII���С�������򣩣���str2�ϲ����ַ���str1�У�Ҫ��ϲ�����ַ�����������ģ������ַ��ظ�����main�����в��Ըú������Ӽ����������������ַ�����Ȼ����øú������������ϲ���Ľ����
��������ʽ��
���дӼ����������������ַ�����������100���ַ���
�������ʽ��
����ϲ���������ַ���
������������
aceg
bdfh
�����������
abcdefgh
������˵����
�������������ַ���aceg��bdfh������ϲ���������ַ���abcdefgh
�����ֱ�׼��
�����ȫ��ȷ��20�֣�ÿ�����Ե�4�֣��ύ�����ļ���Ϊcombine.c��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	return *(char *)a>*(char *)b?1:-1;
}
char * str_bin(char* str1, char* str2)
{
	strcat(str1,str2);
	qsort(str1,(int)strlen(str1),sizeof(char),cmp);
	return str1;
}
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	puts(str_bin(a,b));
	return 1;
}
