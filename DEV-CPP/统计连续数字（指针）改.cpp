#include<stdio.h>
void main()
{
	char a[50],*p=a;
	int b[50]={0},i=0,n=0,t;
	gets(a);
	for(p=a;*p!='\0';p++)
	{	
		if((*p)>='0'&&*p<='9')
		{
			t=(int)(*p-'0');
			b[i]=b[i]*10+t;
		}
			if(*p<'0'||*p>'9')
				i++;
	}
	for(i=0;i<50;i++)
	{
		if(b[i]!=0)
		{
			printf("%d ",b[i]);
			n++;
		}
	}
	printf("\n%d",n);
}