#include<stdio.h>
int main()
{
	long n,i,j,a[41],temp;
	a[0]=0,a[1]=1,a[2]=1,a[3]=2;
	scanf("%ld",&n);
	for(j=4;j<=40;j++)
	{
		a[j]=a[j-1]+a[j-2];
	}

	for(i=0;i<n;i++)
	{	
		scanf("%ld",&temp);
		printf("%ld\n",a[temp]);
	}
	return 0;
}
/*
��һ¥�ݹ�M�����տ�ʼʱ���ڵ�һ������ÿ��ֻ�ܿ���һ���������Ҫ���ϵ�M�������ж������߷���
Input
�����������Ȱ���һ������N����ʾ����ʵ���ĸ�����Ȼ����N�����ݣ�ÿ�а���һ������M��1<=M<=40��,��ʾ¥�ݵļ�����
Output
����ÿ������ʵ�����������ͬ�߷�������
Sample Input
2
2
3
Sample Output
1
2
*/