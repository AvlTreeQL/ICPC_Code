/*

���⣺�����ӡ������

    ��������������������ԭ��ܼ򵥣�����һ���������������½ڵ�ʱ��������ڵ�Ƚϣ���С�򽻸������������������򽻸���������

    ������������ʱ����Ѹýڵ�����Ǹ�λ�á� 

    ���磬10 8 5 7 12 4 ������˳��Ӧ�ý��ɶ�������ͼ1��ʾ�� 

    ����ĿҪ�󣺸�����֪�����֣�������������������ڱ�׼����к����ӡ�ö������� 

    ��������Ϊһ�пո�ֿ���N�������� N<100��ÿ�����ֲ�����10000��
    ����������û���ظ������֡� 

    ���������������ĺ����ʾ�� ��Ӧ�����е����ݣ�Ӧ�����

   |-12
10-|
   |-8-|
       |   |-7
       |-5-|
           |-4


    Ϊ�˱����������ȶԿո����Ŀ����ѿո��þ����棺
...|-12
10-|
...|-8-|
.......|...|-7
.......|-5-|
...........|-4

���磺
�û����룺
10 5 20
����������
...|-20
10-|
...|-5

�����磺
�û����룺
5 10 20 8 4 7
����������
.......|-20
..|-10-|
..|....|-8-|
..|........|-7
5-|
..|-4


��ԴԼ����
��ֵ�ڴ����� < 64M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı���������(ǧ��Ҫ����c��cpp)��



*/
#include<bits/stdc++.h>
using namespace std;
char grap[100][100]={0};
class node
{
public:
	int data;
	node *l;
	node *r;
	node()
	{
		l=NULL;
		r=NULL;
	}
};
void creat(node *head,int data)
{
	if(data>head->data)
	{
		if(head->r) creat(head->r,data);
		else 
		{
			node *b;
			b=new node;
			b->data=data;	
			head->r=b;
		
		}
	}
	else 
	{
		if(head->l) creat(head->l,data);
		else 
		{
			node *b;
			b=new node;
			b->data=data;	
			head->l=b;
		}
	}
}
int num(node *t)
{
	if(t != NULL)
		return num(t->l)+num(t->r)+1;
	else return 0;
}
int numl(node *t)
{
	if(t != NULL)
		return num(t->l);
} 
/*
.......|-20
..|-10-|
..|....|-8-|
..|........|-7
5-|
..|-4

grap[i][j]!='\0'
*/
void fun(node *head,int h,int deep)
{
	if(!head) return ;
	int r=num(head->r);
	int l=num(head->l);
	int rr=0;
	if(head->r) rr=num(head->r->r);
	int ll=0;
	if(head->l) ll=num(head->l->l);
	for(int i=0;i<r;i++)
		grap[i+h][deep]=grap[i+h][deep+1]='.';
		
	grap[r+h][deep]=head->data+'0';
	if(head->r||head->l)grap[r+h][deep+1]='-';
	
	for(int i=1;i<=l;i++)
		grap[r+i+h][deep]=grap[r+i+h][deep+1]='.';
	
	for(int i=0;i<rr;i++)
		grap[i+h][deep+2]=grap[i+h][deep+3]='.';
		
	if(head->r||head->l) grap[rr+h][deep+3]='-';
	for(int i=0;i<r-rr;i++)
	{
		grap[rr+i+h][deep+2]='|';
		grap[rr+i+h][deep+3]='.';
	}
	if(head->r||head->l) grap[r+h][deep+2]='|'; 
	for(int i=1;i<=l-ll;i++)
	{
		grap[r+i+h][deep+2]='|';
		grap[r+i+h][deep+3]='.';
	}
	for(int i=0;i<ll;i++)
	{
		grap[r+1+l-ll+i+h][deep+2]=grap[r+1+l-ll+i+h][deep+3]='.';
	}
	if(head->r||head->l) grap[r+1+l-ll+ll+h][deep+3]='-';
	fun(head->r,h,deep+4);
	fun(head->l,h+1+r,deep+4);
}
int main()
{
	int data;
	node *head;
	head=new node;
	cin>>head->data;
	while(cin>>data)
	{
		creat(head,data);
	}
	fun(head,0,0);
	int n=num(head);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<grap[i][j]!='\0';j++)
		{
			cout<<grap[i][j];
		}
		cout<<endl;
	}
	return 0;
}
