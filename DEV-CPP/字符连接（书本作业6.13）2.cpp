#include<stdio.h>
#include<string.h>
int main()
{
	char a[2][20];
	void fun(char a[][20]);
	gets(a[0]);
	gets(a[1]);
	fun(a);
	puts(a[0]);
	return 0;
}
void fun(char a[][20])
{
	int i,t;
	for(i=0,t=strlen(a[0]);a[1][i]!='\0';i++)
		a[0][t++]=a[1][i];
	a[0][t]='\0';
}
/*	
��������

�Ӽ������������ַ���a��b��Ҫ���ÿ⺯��strcat�Ѵ�b��ǰ����ַ����ӵ���a�У����b�ĳ���С��5�����b������Ԫ�ض����ӵ�a�С���������Ӻ���ַ���a��(�ַ����п��ܺ��пո�

������ʽ

�������У������ַ���a��b���������ַ����ĳ���С��80����

�����ʽ

���һ�У�����ַ���a��

��������

student

and I

�������

studentand I
*/