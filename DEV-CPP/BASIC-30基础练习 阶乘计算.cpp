#include<stdio.h>
#include<string.h>
long long rp=1;
int main()
{
	void fun(long long n,char result[1000]);
 	long long n,i;
 	char result[1000]="\0";
	result[0]=1;
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
 		fun(i,result);
	}
	for(i=rp;i>0;i--)
 	{
 		printf("%c",result[i-1]+'0');
 	}
 	return 0;
} 
void fun(long long n,char result[1000])
{
	char a[1000]="\0",b[1000]="\0",temp,carry;
	long long i,j,p,ap,bp=rp;
	for(i=rp;i>0;i--)
 	{
		b[i-1]=result[i-1];
 		result[i-1]=0;
 	}
	for(i=0;n!=0;i++)
	{
		a[i]=n%10;
		n/=10;
	}
	ap=i;
	for(i=0;i<ap;i++)
	{
		carry=0;
		for(j=0;j<bp;j++)
		{
			temp=a[i]*b[j]+carry;
			carry=temp/10;
			temp=temp%10;
			p=i+j;
			result[p]+=temp;
			carry+=result[p]/10;
			result[p]%=10;
			
		}
		if(carry>0)
		{
			result[i+j]=carry,rp=i+j+1;
		}
		else rp=i+j;
	}	
}
/*
��������
��������һ��������n�����n!��ֵ��
��������n!=1*2*3*��*n��
�㷨����
����n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
������a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
�������Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
�����ʽ
�����������һ��������n��n<=1000��
�����ʽ
�������n!��׼ȷֵ��
��������
10
�������
3628800
*/
