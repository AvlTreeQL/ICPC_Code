/*
��������
�����������[a,b]�������������������ֽ⡣
�����ʽ
����������������a��b��
�����ʽ
����ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
��������
3 10
�������
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
��ʾ
������ɸ������������Ȼ���ٷֽ⡣
���ݹ�ģ��Լ��
����2<=a<=b<=10000
*/
#include<stdio.h>
#include<string.h> 
int t,a[10];
int fun(int n)
{
	int i;
	for(i=2;i<n;i++)
		if(n%i==0) return 0;
	return 1;
}
void fun2(int n)
{
	t=0;
	int p;
	for(p=2;n!=1;p++)
	{	while(n%p==0)
		{
			a[t++]=p,n/=p;
		} 
	}
	a[t]='\0';

}
int main()
{
	int m,n,i,j;

	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++)
	{
//		if(fun(i)==1)printf("%d=%d\n",i,i); 
//		else 
		{
			fun2(i);
			printf("%d=%d",i,a[0]);
			for(j=1;j<t;j++)
			{
				printf("*%d",a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}

