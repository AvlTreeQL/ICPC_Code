#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	node *l;
	node *r;
}node;
node *creat(int *last,int *in,int n)
{
	
	node *b;
	int *temp;
	if(n<=0) return NULL;
	b=new(node);
	b->data=last[n-1];
	temp=find(in,in+n,b->data);
	b->l=creat(last,in,(temp-in));
	b->r=creat(last+(temp-in),temp+1,n-(temp-in)-1);
	return b;
}
int print_at_level(node *T, int level) {  
    if (!T || level < 0)  
        return 0;  
    if (0 == level) {  
        cout << " "<< T->data ;  
        return 1;  
    }  
    return print_at_level(T->l, level - 1) + print_at_level(T->r, level - 1);  
} 
int print_at_level2(node *T, int level) {  
    if (!T || level < 0)  
        return 0;  
    if (0 == level) {  
        cout << T->data;  
        return 1;  
    }  
    return print_at_level(T->l, level - 1) + print_at_level(T->r, level - 1);  
} 
void print_by_level_1(node *T) {  
    int i = 0;  
	print_at_level2(T, i); 
    for (i = 1; ; i++) {  
        if (!print_at_level(T, i))  
            break;  
    }  
    cout << endl;  
} 
int main()
{
	int n,last[30],in[30];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>last[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node *result=creat(last,in,n);
	print_by_level_1(result);
	return 0;
}
