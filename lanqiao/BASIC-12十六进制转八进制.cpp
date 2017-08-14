#include<stdio.h>
char a[20]="\0";
void trans(long long n)//10进制转换成b进制	
{	long long i,j;
	long long o[30];

	for(i=0;n!=0;i++)
	{	
		o[i]=n%16;
		n=n/16;
	}
	for(j=0;j<i;j++)
		switch(o[j])
		{
			case 10:a[i-j-1]='A';break;
			case 11:a[i-j-1]='B';break;
			case 12:a[i-j-1]='C';break;
			case 13:a[i-j-1]='D';break;
			case 14:a[i-j-1]='E';break;
			case 15:a[i-j-1]='F';break;
			default:a[i-j-1]=o[j]+'0';	
		}
	a[i]='\0';
}
/*long long fun(char p[])//a进制转换成10进制
{
	long long n=0,i,t;
	for(i=0;p[i]!='\0';i++)
	{
		switch(p[i])
		{
			case 'A':case 'a': t=10;break;
			case 'B':case 'b': t=11;break;
			case 'C':case 'c': t=12;break;
			case 'D':case 'd': t=13;break;
			case 'E':case 'e': t=14;break;
			case 'F':case 'f': t=15;break;
			default:t=p[i]-'0';
		}
		n=n*16+t;
	}
	return n;
}*/
int main()
{
	long long n;
	scanf("%lld",&n);
	if(n==0) a[0]='0';
	else trans(n);
	puts(a);
	return 0;
}

