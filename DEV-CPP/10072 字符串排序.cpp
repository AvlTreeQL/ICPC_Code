#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	char a[30][20];
	void sort(char a[30][20],int n);
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a[i]);	
	}
	sort(a,n);
	for(i=0;i<n;i++)
	{
		puts(a[i]);	
	}
	return 0;
}
void swap(char *a,char *b)
{
	char c[10];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);

}
void sort(char a[30][20],int n)
{
	int i,j;
//	void swap(char *a,char *b);
	for(i=0;i<n-1;i++)
	{
	
		for(j=0;j<n-1-i;j++)
		{	
			if(strcmp(a[j],a[j+1])>0)
			swap(a[j],a[j+1]);
		/*	t=0;
			if(a[j][t]>a[j+1][t])
				swap(a[j],a[j+1]);
			else if(a[j][t]==a[j+1][t])
			{
				for(t=1;a[j][t]!='\0'&&a[j+1][t]!='\0';t++)
				{
					if(a[j][t]>a[j+1][t])
					{
						swap(a[j],a[j+1]);
						break;
					}
					if(a[j][t]<a[j+1][t])
						break;
				}
			
			}*/
		}
	}

}

/*
【问题描述】按字典顺序输出某班所有人的名单。
【输入形式】一组测试数据，第一行为一个整数N，表示本班有N个人(N<=30)，接下来的N行中每行一个人名 (人名均由小写字母组成，并且名字长度小于20)。
【输出形式】按字典顺序排列的人员名单。每个人名占一行。
【样例输入】
5
zhangsan
liyang
wangxiao
liqing
wuhui
2
liqy
liyq
【样例输出】liqing
                    liyang
                    wangxiao
                    wuhui
                    zhangsan
【样例说明】某班有5个人,名字为zhangsan、liyang、wangxiao、liqing、wuhui,  
                   按字典的排列顺序为：liqing、liyang、wangxiao、wuhui、zhangsan。
【评分标准】本题共2个测试点，每个测试点1.0分，共2.0分。
*/