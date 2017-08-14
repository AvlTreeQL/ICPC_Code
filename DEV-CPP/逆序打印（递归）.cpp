#include <stdio.h>
int main()
{
	int i=5;
	void palin(int n);
	printf("\40:");
	palin(i);
	printf("\n");
	return 0;
}
void palin(int n)
{
	char next;
	if(n<=1)
	{
		next=getchar();
		printf("\n\0:");
		putchar(next);
	}
	else
	{
		next=getchar();
		palin(n-1);
		putchar(next);
	}
}