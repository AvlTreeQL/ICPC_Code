/*

标题：横向打印二叉树

    二叉树可以用于排序。其原理很简单：对于一个排序二叉树添加新节点时，先与根节点比较，若小则交给左子树继续处理，否则交给右子树。

    当遇到空子树时，则把该节点放入那个位置。 

    比如，10 8 5 7 12 4 的输入顺序，应该建成二叉树如图1所示。 

    本题目要求：根据已知的数字，建立排序二叉树，并在标准输出中横向打印该二叉树。 

    输入数据为一行空格分开的N个整数。 N<100，每个数字不超过10000。
    输入数据中没有重复的数字。 

    输出该排序二叉树的横向表示。 对应上例中的数据，应输出：

   |-12
10-|
   |-8-|
       |   |-7
       |-5-|
           |-4


    为了便于评卷程序比对空格的数目，请把空格用句点代替：
...|-12
10-|
...|-8-|
.......|...|-7
.......|-5-|
...........|-4

例如：
用户输入：
10 5 20
则程序输出：
...|-20
10-|
...|-5

再例如：
用户输入：
5 10 20 8 4 7
则程序输出：
.......|-20
..|-10-|
..|....|-8-|
..|........|-7
5-|
..|-4


资源约定：
峰值内存消耗 < 64M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型(千万不要混淆c和cpp)。



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
