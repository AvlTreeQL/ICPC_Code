#include<stdio.h>
int main()
{
	int m,n,i,j;
	char c='A',d,e;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{	c++;
		e=c-1;
		for(j=0;j<i&&j<n;j++)
		{	
			printf("%c",e--);
		}
		d='A';
		for(j=i;j<n;j++)
			printf("%c",d++);
		printf("\n");
	}	
	return 0;
}
/*
��������
������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ�
�����ʽ
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������
�����ʽ
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�
��������
5 7
�������
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
���ݹ�ģ��Լ��
1 <= n, m <= 26��
*/
