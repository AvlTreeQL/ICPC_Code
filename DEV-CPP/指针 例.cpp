#include<stdio.h>
int main()
{
	int a=100;
	printf("%d\n",*((int *)0x0019FF3C));
	*((int *)0x0019FF3C)=200;
	printf("%d\n",a);
	return 0;
}
// (int *)0x0019FF3C �൱�� int *p=&a; 
// p����(int *)0x0019FF3C  a�ĵ�ַ
// *p����*((int *)0x0019FF3C))   a��ֵ