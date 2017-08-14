#include<stdio.h>
void trans(long n,long b);
char q[50];
int main()
{
	long n;
	scanf("%d",&n);
	trans(n,16);
	puts(q);
	return 0;
}
void trans(long n,long b)//10进制转换成b进制	
{	int i,j;
	long o[10];
	q[0]='0';
	for(i=0;n!=0;i++)
	{	
		o[i]=n%b;
		n=n/b;
	}
	for(j=0;j<i;j++)
	switch(o[j])
	{
		case 10:q[i-j-1]='A';break;
		case 11:q[i-j-1]='B';break;
		case 12:q[i-j-1]='C';break;
		case 13:q[i-j-1]='D';break;
		case 14:q[i-j-1]='E';break;
		case 15:q[i-j-1]='F';break;
		default:q[i-j-1]=o[j]+'0';	
	}
}
/*
BCD数是用一个字节来表达两位十进制的数，每四个比特表示一位。
所以如果一个BCD数的十六进制是0x12，它表达的就是十进制的12。
但是小明没学过BCD，把所有的BCD数都当作二进制数转换成十进制输出了。
于是BCD的0x12被输出成了十进制的18了！
现在，你的程序要读入这个错误的十进制数，然后输出正确的十进制数。
提示：你可以把18转换回0x12，然后再转换回12。
输入格式：

输入在一行中给出一个[0, 153]范围内的正整数，保证能转换回有效的BCD数，也就是说这个整数转换成十六进制时不会出现A-F的数字。
输出格式：

输出对应的十进制数。
输入样例：

18
输出样例：

12
*/