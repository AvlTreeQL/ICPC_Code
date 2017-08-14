#include<stdio.h>
#include<string.h>
void fun(int a[100],int n,int m);
int b[100];
int main()
{
	int n,m,i;
	int a[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	fun(a,n,m);
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	return 0;
}
void fun(int a[100],int n,int m)
{
	int i,j=0;
	for(i=n-m;i<n;i++)
		b[j++]=a[i];
	for(i=0;i<n-m;i++)
		b[j++]=a[i];
	b[j]='\0';
}

/*
有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数，见图。

 aa.bmp



写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数。用指针方法实现。

输入形式

输入两行，第一行输入n和m，第二行输入n个整数。

输出形式

输出一行，输出调整后的n个数。

样例输入

6 2
1 2 3 4 5 6

样例输出

5 6 1 2 3 4
*/