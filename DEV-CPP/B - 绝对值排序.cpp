#include<stdio.h>
int main()
{
	long i,a=0,n[200],b[200][200];
	void sort(long a[200],long n);
	long fun(long a);
	do
	{
		scanf("%ld",&n[a]);
		for(i=0;i<n[a];i++)
			scanf("%ld",&b[a][i]);
		a++;
	}while(n[a-1]!=0);
	for(i=0;i<a-1;i++)
	{
		sort(b[i],n[i]);
		printf("\n");
	}
	return 0;
}
void sort(long a[200],long n)
{
	long i,j,t;
	long fun(long a);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(fun(a[j])<fun(a[j+1]))
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	for(i=0;i<n-1;i++)
		printf("%ld ",a[i]);
	printf("%ld",a[i]);
}
long fun(long a)
{
	if(a>=0) return a;
	else return -a;
}
/*
����n(n<=100)�����������վ���ֵ�Ӵ�С������������Ŀ��֤����ÿһ������ʵ�������е����ľ���ֵ������ȡ�
Input
���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ������Ϊn,������n��������n=0��ʾ�������ݵĽ������������� 
Output
����ÿ������ʵ������������Ľ����������֮����һ���ո������ÿ������ʵ��ռһ�С�
Sample Input
3 3 -4 2
4 0 1 2 -3
0
Sample Output
-4 3 2
-3 2 1 0
*/