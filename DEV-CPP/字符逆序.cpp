#include<stdio.h>
#include<string.h>
int main()
{
	char a[50],b[50];
	char t;
	int i,j;
	gets(a);
	for(i=0,j=strlen(a)-1;i<j;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	printf("%s",a);
	return 0;
}