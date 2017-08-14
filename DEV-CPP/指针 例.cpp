#include<stdio.h>
int main()
{
	int a=100;
	printf("%d\n",*((int *)0x0019FF3C));
	*((int *)0x0019FF3C)=200;
	printf("%d\n",a);
	return 0;
}
// (int *)0x0019FF3C 相当于 int *p=&a; 
// p就是(int *)0x0019FF3C  a的地址
// *p就是*((int *)0x0019FF3C))   a的值