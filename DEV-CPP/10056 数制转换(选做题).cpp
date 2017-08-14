#include<stdio.h>
int main()
{
	long a,b,i,j,n,q[10];
	char p[10];
	long fun(long a,char p[]);
	scanf("%ld%s%ld",&a,p,&b);
	n=fun(a,p);
	for(i=0;n!=0;i++)
	{	q[i]=n%b;
		n=n/b;
	}
	for(j=i-1;j>=0;j--)
	switch(q[j])
	{
		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		default:printf("%ld",q[j]);
	}
	return 0;
}
long fun(long a,char p[])
{
	int i;
	long n=0,t;
	for(i=0;p[i]!='\0';i++)
	{
		switch(p[i])
		{
			case 'A':case 'a': t=10;break;
			case 'B':case 'b': t=11;break;
			case 'C':case 'c': t=12;break;
			case 'D':case 'd': t=13;break;
			case 'E':case 'e': t=14;break;
			case 'F':case 'f': t=15;break;
			default:t=p[i]-'0';
		}
		n=n*a+t;
	}
	return n;
}

/*

【问题描述】求任意两个不同进制非负整数的转换（2进制~16进制），所给整数在long所能表达的范围之内。不同进制的表示符号为(0，1，....，9，A，B，C，D，E，F)。注意：不同进制可能不能直接转换，如八进制与十六进制。可以考虑不同进制与十进制的转换，即借助于十进制实现任意两个不同进制的转换。
【输入形式】输入只有一行，包含三个整数a，n，b。a表示其后的n是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，且2=<a，b<=16。
【输出形式】输出包含一行，为转换后的b进制整数。输出时字符号全部用大写表示，即（0 ，1，...，9，A，B，C，D，E，F）。
【样例输入】15 AAB3 7
【样例输出】210306
【样例说明】15进制的数AAB3，转换为7进制后的数为210306。
【评分标准】本题共4个测试点，每个测试点0.25分，总分1.0分。
*/