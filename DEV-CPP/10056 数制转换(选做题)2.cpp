#include<stdio.h>
char q[10];
int main()
{
	long a,b,n;
	char p[10];
	long fun(long a,char p[]);
	void trans(long n,long b);
	scanf("%ld%s%ld",&a,p,&b);
	n=fun(a,p);
	trans(n,b);
	puts(q);
	return 0;
}
void trans(long n,long b)//10����ת����b����	
{	int i,j;
	long o[10];
	for(i=0;n!=0;i++)
	{	
		o[i]=n%b;
		n=n/b;
	}
	for(j=0;j<i;j++)
	switch(o[j])
	{
		case 10:q[i-j-1]='A';break;
		case 11:q[i-j-1]='B';break;
		case 12:q[i-j-1]='C';break;
		case 13:q[i-j-1]='D';break;
		case 14:q[i-j-1]='E';break;
		case 15:q[i-j-1]='F';break;
		default:q[i-j-1]=o[j]+'0';	
	}
}
long fun(long a,char p[])//a����ת����10����
{
	int i;
	long n=0,t;
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
		n=n*a+t;
	}
	return n;
}

/*

������������������������ͬ���ƷǸ�������ת����2����~16���ƣ�������������long���ܱ��ķ�Χ֮�ڡ���ͬ���Ƶı�ʾ����Ϊ(0��1��....��9��A��B��C��D��E��F)��ע�⣺��ͬ���ƿ��ܲ���ֱ��ת������˽�����ʮ�����ơ����Կ��ǲ�ͬ������ʮ���Ƶ�ת������������ʮ����ʵ������������ͬ���Ƶ�ת����
��������ʽ������ֻ��һ�У�������������a��n��b��a��ʾ����n��a����������b��ʾ����a��������nת����b����������a��b��ʮ������������2=<a��b<=16��
�������ʽ���������һ�У�Ϊת�����b�������������ʱ�ַ���ȫ���ô�д��ʾ������0 ��1��...��9��A��B��C��D��E��F����
���������롿15 AAB3 7
�����������210306
������˵����15���Ƶ���AAB3��ת��Ϊ7���ƺ����Ϊ210306��
�����ֱ�׼�����⹲4�����Ե㣬ÿ�����Ե�0.25�֣��ܷ�1.0�֡�
*/