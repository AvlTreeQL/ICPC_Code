#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
	return *(int *)a<*(int *)b?1:-1;
}
	struct songer
	{
		char b[20];
		int s[4];
	}a[15],c;
int main()
{
	int n,sum[15],i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d%d",a[i].b,&a[i].s[0],&a[i].s[1],&a[i].s[2],&a[i].s[3]);
		qsort(a[i].s,4,sizeof(int),comp);
	}
	for(i=0;i<n;i++)
	{
		sum[i]=a[i].s[0]+a[i].s[1]+a[i].s[2];
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(sum[j]<sum[j+1])
			{
				t=sum[j];
				sum[j]=sum[j+1];
				sum[j+1]=t;
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
			else if(sum[j]==sum[j+1]&&a[j].s[3]<a[j+1].s[3])
			{
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	for(i=0;i<n;i++)
	{
		printf("%-10s%-6d\n",a[i].b,sum[i]);
	}
	return 0;
}
/*
【问题描述】在歌唱比赛中，有4个评委给选手打分（所打分数为<=10的正整数），每个参赛选手的这4个得分中至少有一个是最低分。规定：每个选手去掉一个最低得分后，余下3个得分之和为最后的总分。现有N（N<15）个选手参加比赛，每个选手的信息包括编号（长度小于10的字符串）、第1个评委的打分、第2个评委的打分、第3个评委的打分、第4个评委的打分。读入参赛选手的信息并按总分由高到低的顺序输出编号和总分。若出现总分相同者，则其最低分小的选手排在后面。
【输入形式】第一行为一个整数N，表示参赛选手人数，接下来的N行中每行包含一个参赛选手的相关 数据，各数据之间由空格分隔。
【输出形式】输出占N行，为按总分由高到低排序的所有参赛选手的主要信息。每一行包括一个参赛选手的编号和总分。所有数据均左对齐。 参考输出格式为："%-10s%-6d\n"。
【样例输入
3 
0A01001   7  6  8  5 
0A01002   8  8  7  9
0A01003   8  7  9  6
【样例输出】0A01002   25
                        0A01003   24
                        0A01001   21
【样例说明】参赛选手共3人, 第1个人的数据为"0A01001   7  6  8  5 ", 第2个人的信息为"0A01002   8  8  7  9 ", 第3个人的信息为"0A01003   8  7  9  6 "。按总分由低到高输出选手编号和总分的顺序为：0A01002   25， 0A01003   24，0A01001   21。
【评分标准】本题有4个测试点，每个测试点5分，共20分。
*/