#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	node *l;
	node *r;
}node;
int print(node *p,int le)
{
	if(p==NULL||le<0)
		return 0;
	if(le==0)
	{
		cout<<' '<<p->data;
		return 1;
	}
	return print(p->r,le-1)+print(p->l,le-1);	
}
int print(node *p,int le,int iii)
{
	if(p==NULL||le<0)
		return 0;
	if(le==0)
	{
		cout<<p->data;
		return 1;
	}
	return print(p->r,le-1)+print(p->l,le-1);	
}
void print(node *p)
{
	int i=0;
	print(p,i,1);
	while(1)
	{
		i++;
		if(print(p,i)==0) break;
		
	}
}
node *creat(int *first,int *in,int n)
{
	if(n<=0) return NULL;
	node *b;
	int *temp;
	b=new(node);
	b->data=first[0];
	temp=find(in,in+n,first[0]);
	int k=temp-in;
	b->l=creat(first+1,in,k);
	b->r=creat(first+k+1,in+k+1,n-k-1);
	return b;
}

int main()
{
	int n,first[30],in[30];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>first[i];
	}
	node *result=creat(first,in,n);
	print(result);
	return 0;
}
