#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int x;
    int n;
    struct stu*next;
};
struct stu*creat()
{
    struct stu*head;
    struct stu*tail;
    struct stu*p;
    p=(struct stu*)malloc(sizeof(struct stu));
    scanf("%d%d",&p->x,&p->n);
    head=NULL;
    tail=p;
    while(p->x!=-1&&p->n!=-1)
    {
        if(head==NULL) head=p;
        else tail->next=p;
        tail=p;
        p=(struct stu*)malloc(sizeof(struct stu));
        scanf("%d%d",&p->x,&p->n);
    }
    tail->next=NULL;
    return head;
}
int main()
{
    struct stu*a,*b,*heada,*headb;
    heada=a=creat();
    headb=b=creat();
    while(b)
    {
        if(heada->x==b->x) 
            heada=heada->next;
        while(a->next)
        {
            if(a->next->x==b->x)
                a->next=a->next->next;
            if(a->next!=NULL)a=a->next;
        }
        a=heada;
        b=b->next;
    }
    while(a)
    {
        printf("%d %d\n",a->x,a->n);
        a=a->next;
    }
    return 0;
}
/*
1 90
2 98
3 95
4 94
5 92
-1 -1
2 98
4 94
-1 -1
 
1 90
3 95
5 92
*/