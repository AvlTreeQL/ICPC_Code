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
问题描述
输入三个整数，按由小到大的顺序输出。用指针方法实现。
输入形式
输入一行，只包括三个整数。
输出形式
输出一行，按小到大的顺序输出这三个整数，各个整数间以空格分隔。
样例输入
3 2 1
样例输出
1 2 3
*/