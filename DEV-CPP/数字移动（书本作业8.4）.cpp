#include<stdio.h>
#include<string.h>
void fun(int a[100],int n,int m);
int b[100];
int main()
{
	int n,m,i;
	int a[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	fun(a,n,m);
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	return 0;
}
void fun(int a[100],int n,int m)
{
	int i,j=0;
	for(i=n-m;i<n;i++)
		b[j++]=a[i];
	for(i=0;i<n-m;i++)
		b[j++]=a[i];
	b[j]='\0';
}

/*
��n��������ʹǰ�����˳�������m��λ�ã����m�������ǰ��m��������ͼ��

 aa.bmp



дһ������ʵ�����Ϲ��ܣ���������������n����������������n��������ָ�뷽��ʵ�֡�

������ʽ

�������У���һ������n��m���ڶ�������n��������

�����ʽ

���һ�У�����������n������

��������

6 2
1 2 3 4 5 6

�������

5 6 1 2 3 4
*/