#include <stdio.h>
#include <string.h>
int main()
{
	char a[2][20],i;
	int min(int x,int y);
	gets(a[0]);	
	gets(a[1]);
	for(i=0;i<strlen(a[0]);i++)
		printf("%c",a[0][i]);
	for(i=0;i<min(strlen(a[2]),5);i++)
		printf("%c",a[1][i]);
	return 0;
}
int min(int x,int y)
{
	int min;
	if(x>y) min=y;
	else min=x;
	return min;
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