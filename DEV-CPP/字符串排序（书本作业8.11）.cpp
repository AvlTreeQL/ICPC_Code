#include<stdio.h>
#include<string.h>
void swap(char *a,char *b);
void sort(char a[80][80],int n);
int main()
{
	int n,i;
	char a[80][80];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
		gets(a[i]);
	sort(a,n);
	for(i=0;i<n;i++)
		puts(a[i]);
	return 0;
}
void sort(char a[80][80],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(strcmp(a[j],a[j+1])>0)
				swap(a[j],a[j+1]);
}
void swap(char *a,char *b)
{
	char c[80];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}
/*
问题描述
在主函数中输入n个的字符串。用另一函数用指针方法对它们按照ASCII码从小到大的顺序排序。然后在主函数输出这n个已排好序的字符串。（n不大于10，每个字符串的长度不大于80）
输入形式
输入n+1行，第一行是正整数n，第二行到第n+1行是n个字符串。
输出形式
输出n行，给出排序好的n个字符串。
样例输入
5
Bbbb b
Aaaa a
Ccccc c
Eeeee e
Ddddd
样例输出
Aaaa a
Bbbb b
Ccccc c
Ddddd
Eeeee e
*/