#include <stdio.h>
#include <stdlib.h>
struct monkey
{
	int n;
	struct monkey *next;
};
int creat(int a,int b)
{
	struct monkey *head;
	struct monkey *tail;
	struct monkey *p,*q;
	p=(struct monkey *)malloc(sizeof(struct monkey));
	p->n=1;
	head=NULL;
	tail=p;
	int i=1,num;
	while(a--)
	{
		if(head==NULL)
			head=p;
		else 
			tail->next=p;
		tail=p;
		if(a==0) break;
		p=(struct monkey *)malloc(sizeof(struct monkey));
		p->n=++i;
	}
	tail->next=head;
	num=i;
	p=head;
	while(num!=1)
	{
		for(i=1;i<b;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		p=p->next;
		num--;
	}
	return p->n;
}

int main()
{
	int a,b,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",creat(a,b));
	}
	
	return 0;
}


/*
【问题描述】
有N只猴子，从1~N进行编号。
它们按照编号的顺时针方向排成一个圆圈，然后从第一只猴子开始报数。
第一只猴子报的第一个数字为1，以后每只猴子报的数字都是它们前面猴子所报数字加 1。
如果一个猴子报的数字是M，则该猴子出列，下一个猴子重新从1开始报数，直到所有猴子都出列为止，最后一个出列的猴子胜出。
你的任务是对于给定猴子数量和报数上限值M，确定出能够被选作大王的猴子的编号。
【输入形式】第一行为一个整数N，表示测试数据的组数，接下来的N行中每行包含两个整数，第一个数是猴子的个数，第二个数是报数上限值M（M>1）,两数之间由空格分隔。
【输出形式】输出共N行，每行为对应输入行获胜猴子的编号。
【样例输入】
2 
8 5
5 8
【样例输出】
3 
1
【样例说明】有2组测试数据。
                       第1组有8个猴子，报数上限是5，被选作大王的猴子编号为3；
                       第2组有5个猴子，报数上限是8，被选作大王的猴子编号为1。
【评分标准】本题共1个测试点，共1.0分。
*/