#include<stdio.h>
int main()
{
	long a,b,i,j,n,q[10];
	char p[10];
	long fun(long a,char p[]);
	scanf("%ld%s%ld",&a,p,&b);
	n=fun(a,p);
	for(i=0;n!=0;i++)
	{	q[i]=n%b;
		n=n/b;
	}
	for(j=i-1;j>=0;j--)
	switch(q[j])
	{
		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		default:printf("%ld",q[j]);
	}
	return 0;
}
long fun(long a,char p[])
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