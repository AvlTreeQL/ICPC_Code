#include<stdio.h>
int main()
{
	int i,n,d=0,x=0,s=0,k=0,o=0;
	char c;
	scanf("%d",&n);
	for(i=0;i<=n;)
	{
		scanf("%c",&c);
		if(c=='\n') 
			i++;
		else
			if(c>='A'&&c<='Z') 
				d++;
			else
				if(c>='a'&&c<='z') 
					x++;
				else
					if(c>='0'&&c<='9') 
						s++;
					else
						if(c==' ') 
							k++;
						else o++;
 	}
	printf("%d %d %d %d %d",d,x,s,k,o);
	return 0;
}
/*	
问题描述
有一篇文章，共有n（n不大于20）行文字，每行有若干个字符组成（字符个数不超过80）。要求分别统计出其中英文大写字母、小写字母、数字、空格以及其它字符的个数。
输入形式
输入n+1行。
第一行输入整数n；
第二行到n+1行分别输入n行字符串；
输出形式
输出一行，给出这篇文章英文大写字母、小写字母、数字、空格以及其它字符的个数，各个数值以空格分隔。
样例输入
4
1.I 'm an office worker.   2.I work for the government.
3.I 'm happy to meet you.  4.I like your sense of humor. 
5.I 'm glad to see you again.  6.I 'll call you.
7.I feel like sleeping/ taking a walk.  8.I want something to eat.
样例输出
8 142 8 48 21
*/