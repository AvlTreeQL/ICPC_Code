/*��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ
������һ��Ϊһ������n��
�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ
�������һ�У�����С�����˳��������������С�
��������
5
8 3 6 4 9
�������
3 4 6 8 9
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
	return *(int *)a>*(int *)b?1:-1;
}
int main()
{
	int i,n,a[200];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
} 
