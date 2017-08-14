#include<stdio.h>

int main(void)
{
  int i,a,b;
  scanf("%d%d",&a,&b);
  
  for (i = a; i <= b; i++)
	  if (i * i % 10 == i || i * i % 100 == i)
		  printf("%d\n",i);
  return (0);
}
