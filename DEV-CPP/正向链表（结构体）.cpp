#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int a;
	struct stu *next;
};
struct stu *creat(int n)
{
	struct stu *head;
	struct stu *p;
	struct stu *tail;
	p=(struct stu *)malloc(sizeof(struct stu));
	scanf("%d",&p->a);
	head=NULL;
	tail=p;
	while(n--)
	{
		if(head==NULL)
			head=p; 
		else
			tail->next=p;
		tail=p;
		if(n==0) break;
		p=(struct stu *)malloc(sizeof(struct stu));
		scanf("%d",&p->a);	
	}
	tail->next=NULL;
	return head;
}
void print(struct stu *head)
{
	struct stu *p=head;
	while(p)
	{
		printf("%d ",p->a);
		p=p->next;
	}
}
int main()
{
	struct stu*p;
	int n;
	scanf("%d",&n);
	p=creat(n);
	print(p);
	return 0;
}
