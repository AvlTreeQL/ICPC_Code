/*��������
�Ӽ�������һ���ַ����������е�Сд��ĸȫ��ת���ɴ�д��ĸ��Ȼ�������һ�������ļ�"test.txt"�б��档������ַ�����"��"������
������ʽ
����һ�У�ֻ����һ���ַ�����������ַ�����"��"�����������������浽�ļ��У���
�����ʽ
������ַ�ת���󱣴浽test.txt�ļ��С�
��������
abc 123!
�������*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("test.txt","w"))==NULL)
	{printf("cannot open tihe file\n");exit(0);}
	ch=getchar();
	do{
		if((ch<='z')&&(ch>='a'))
			ch=ch-'a'+'A';
		fputc(ch,fp);
		ch=getchar();
	}while(ch!='!');
	fclose(fp);
	return 0;
}