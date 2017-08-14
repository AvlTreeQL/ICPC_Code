#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
} Node;
Node *CreateBT2(int *post,int *in,int n)      
{
    Node *b;
    int r,*p,k;
    if(n<=0)return NULL;
    r=*(post+n-1);
    b=new(Node);
    b->data=r;
    for(p=in; p<in+n; p++)
        if(*p==r)break;
    k=p-in;
    b->lchild=CreateBT2(post,in,k);
    b->rchild=CreateBT2(post+k,p+1,n-k-1);
    return b;
}
void Print(Node *r)                           
{
    Node *p;
    Node *pr[100];
    int rear=-1,front=-1;
    rear++;
    pr[rear]=r;
    
    front++;
    p=pr[front];
    cout<<p->data;
    
	if(p->lchild!=NULL)
    {
        rear++;
        pr[rear]=p->lchild;
    }
    if(p->rchild!=NULL)
    {
        rear++;
        pr[rear]=p->rchild;
    }
	while(rear!=front)
    {
        front++;
        p=pr[front];
        cout<<' '<<p->data;
        
		if(p->lchild!=NULL)
        {
            rear++;
            pr[rear]=p->lchild;
        }
        if(p->rchild!=NULL)
        {
            rear++;
            pr[rear]=p->rchild;
        }
    }
}
int main()
{
    int N,i;
    cin>>N;
	int a[100],b[100];
    for(i=0; i<N; i++)
        cin>>a[i];
    for(i=0; i<N; i++)
        cin>>b[i];
    Node* result=CreateBT2(b,a,N);
    Print(result);
    return 0;
}