#include<stdio.h>
 
int main()
{
      int a,b,c;
      int *pa,*pb,*pc;
      void swap(int *p1,int *p2);
      pa=&a;
      pb=&b;
      pc=&c;
      scanf("%d%d%d",&a,&b,&c);
      if(a>b) swap(pa,pb);
      if(b>c) swap(pb,pc);
      if(a>b) swap(pa,pb);
      printf("%d %d %d\n",*pa,*pb,*pc);
      return 0;
}
void swap(int *p1,int *p2)
{
     int p;
     p=*p1;
     *p1=*p2;
     *p2=p;
}
/*
��������
������������������С�����˳���������ָ�뷽��ʵ�֡�
������ʽ
����һ�У�ֻ��������������
�����ʽ
���һ�У���С�����˳����������������������������Կո�ָ���
��������
3 2 1
�������
1 2 3
*/