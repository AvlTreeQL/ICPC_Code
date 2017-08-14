/*问题描述
从键盘输入一个字符串，将其中的小写字母全部转换成大写字母，然后输出到一个磁盘文件"test.txt"中保存。输入的字符串以"！"结束。
输入形式
输入一行，只包括一个字符串，输入的字符串以"！"结束（“！”不保存到文件中）。
输出形式
输入的字符转换后保存到test.txt文件中。
样例输入
abc 123!
样例输出*/
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