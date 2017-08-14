#include<stdio.h>
int main()
{
	char a[20],b[20];
	int fun(char a[]);
	gets(a);
	gets(b);
	printf("%d",fun(a)+fun(b));
	return 0;
}
int fun(char a[])
{
	int i,t,n=0;
	for(i=0;a[i]!='\0';i++)
	{
		switch(a[i])
		{
			case 'A':case 'a':t=10;break;
			case 'B':case 'b':t=11;break;
			case 'C':case 'c':t=12;break;
			case 'D':case 'd':t=13;break;
			case 'E':case 'e':t=14;break;
			case 'F':case 'f':t=15;break;
			case 'G':case 'g':t=16;break;
			default:t=a[i]-'0';
		}
		n=n*16+t;
	}
	return n;
}
/*
	
【问题描述】对输入的两个十六进制数(两个字符串)，将其转换成十进制后再求和。要求十六进制到十进制的转换功能由函数完成。例如：输入3a1转换为十进制后为929，80转换为十进制后为128，所以和为1057。
【输入形式】输入包括两行，每行为一个十六进制数。注意：本题中的十六进制数中的英文字符以小写字母表示。
【输出形式】输出包括一行，为两数之和的十进制表示。
【样例输入】
3a1
80
【样例输出】1057
【样例说明】16进制数3a1和80转换为10进制数之后的和为1057(输出该数时后面不加换行符)。
【评分标准】本题共4个测试点，每个测试点0.25分，共1.0分。
*/