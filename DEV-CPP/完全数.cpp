#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,i,t=0;
	int r(int i);
	scanf("%d %d",&m,&n);
	if(m<=0) m=0;
	for(i=m;i<=n;i++)
	{
		if(r(i)==1) 
		{
			printf("%d ",i);
			t+=1;
		}
	}
	if(t==0) printf("no");
	return 0;
}
int r(int i)
{
	int a=0,b,c;
	b=i+100;
	c=i+268;
	if((int)sqrt(b)*(int)sqrt(b)==b&&(int)sqrt(c)*(int)sqrt(c)==c) a=1;
	return a;
}
/*	
问题描述
完全数是这样一个整数，它加上100后是一个完全平方数，它加上268也是一个完全平方数。编程程序求出m，n之间所有完全数（包括m和n），其中n>m。
输入形式
输入一行，包括整数m和n。
输出形式
输出一行，输出m与n间的所有完全数，各数之间以空格分隔。若没有，则输出“no”。
样例输入
1 10000
样例输出
        21 261 1581
*/