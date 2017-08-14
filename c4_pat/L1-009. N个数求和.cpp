#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void fun1(long &a,long &b)
{
	long i;
	for(i=2;i<=sqrt(abs(a))||i<=sqrt(abs(b));i++)
	{
		while(a%i==0&&b%i==0)
			a/=i,b/=i;
	}
}
void fun(long a,long b,long &fz,long &fm)
{
	if(b!=fm)
	{
		a*=fm;
		fm*=b;
		fz*=b;
		fz+=a;
	}
	else
	{
		fz+=a;
	}
}

int main()
{
	long n,a,b,fz,fm,i;
	cin>>n;
	scanf("%ld/%ld",&fz,&fm);
	for(i=1;i<n;i++)
	{
		scanf("%ld/%ld",&a,&b);
		fun1(a,b);
		fun(a,b,fz,fm);	
		if(abs(fz)>1000||fz>1000)fun1(fz,fm);
	}
	for(i=2;i<=abs(fz)||i<=abs(fm);i++)
	{
		while(fz%i==0&&fm%i==0)
			fm/=i,fz/=i;
	}
	if(fz%fm==0) cout<<fz/fm<<endl;
	else if(abs(fz)>fm) cout<<fz/fm<<' '<<fz%fm<<'/'<<fm<<endl;
	else cout<<fz<<'/'<<fm<<endl;
	return 0;
}
/*
 L1-009. N�������
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
�����Ҫ��ܼ򵥣�������N�����ֵĺ͡��鷳���ǣ���Щ��������������������/��ĸ������ʽ�����ģ�������ĺ�Ҳ����������������ʽ��

�����ʽ��

�����һ�и���һ��������N��<=100�������һ�а���ʽ��a1/b1 a2/b2 ...������N������������Ŀ��֤���з��Ӻͷ�ĸ���ڳ����ͷ�Χ�ڡ����⣬�����ķ���һ�������ڷ���ǰ�档

�����ʽ��

����������ֺ͵������ʽ ���� �������д�ɡ��������� �������֡������з�������д�ɡ�����/��ĸ����Ҫ�����С�ڷ�ĸ��������û�й����ӡ�����������������Ϊ0����ֻ����������֡�

��������1��
5
2/5 4/15 1/30 -2/60 8/3
�������1��
3 1/3
��������2��
2
4/3 2/3
�������2��
2
��������3��
3
1/3 -1/6 1/8
�������3��
7/24
 */
