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
������������
��Nֻ���ӣ���1~N���б�š�
���ǰ��ձ�ŵ�˳ʱ�뷽���ų�һ��ԲȦ��Ȼ��ӵ�һֻ���ӿ�ʼ������
��һֻ���ӱ��ĵ�һ������Ϊ1���Ժ�ÿֻ���ӱ������ֶ�������ǰ������������ּ� 1��
���һ�����ӱ���������M����ú��ӳ��У���һ���������´�1��ʼ������ֱ�����к��Ӷ�����Ϊֹ�����һ�����еĺ���ʤ����
��������Ƕ��ڸ������������ͱ�������ֵM��ȷ�����ܹ���ѡ�������ĺ��ӵı�š�
��������ʽ����һ��Ϊһ������N����ʾ�������ݵ���������������N����ÿ�а���������������һ�����Ǻ��ӵĸ������ڶ������Ǳ�������ֵM��M>1��,����֮���ɿո�ָ���
�������ʽ�������N�У�ÿ��Ϊ��Ӧ�����л�ʤ���ӵı�š�
���������롿
2 
8 5
5 8
�����������
3 
1
������˵������2��������ݡ�
                       ��1����8�����ӣ�����������5����ѡ�������ĺ��ӱ��Ϊ3��
                       ��2����5�����ӣ�����������8����ѡ�������ĺ��ӱ��Ϊ1��
�����ֱ�׼�����⹲1�����Ե㣬��1.0�֡�
*/