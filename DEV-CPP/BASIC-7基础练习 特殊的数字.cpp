#include<stdio.h>
#include<math.h>
int main()
{
	int fun(int n);
	int i,j,k;
	for(i=100;i<=999;i++)
		if(fun(i)==1) printf("%d\n",i);
	return 0;
}
int fun(int n)
{	int sum=0,temp=n,temp2;
	while(n!=0)
	{ 
//		sum+=pow(n%10,3); 
		temp2=n%10;
		sum+=temp2*temp2*temp2;
		n/=10;
	}
	if(sum==temp) return 1;
	else return 0;
}
/*
��������
����153��һ���ǳ��������������������ÿλ���ֵ������ͣ���153=1*1*1+5*5*5+3*3*3���������������������������λʮ��������
�����ʽ
��������С�����˳�����������������λʮ��������ÿ����ռһ�С�
*/
