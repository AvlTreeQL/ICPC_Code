#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,max,min,i;
	long long sum;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	scanf("%d",&a[0]);
	max=min=sum=a[0];
	for(i=1;i<n;i++)
	{scanf("%d",&a[i]);
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
		sum+=a[i];
	}
	printf("%d\n%d\n%lld\n",max,min,sum);
	return 0;
} 
/*
��������
����n�������ҳ���n���������ֵ����Сֵ���͡�
�����ʽ
��һ��Ϊ����n����ʾ���ĸ�����
�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��
�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
���ݹ�ģ��Լ��
1 <= n <= 10000��
*/
