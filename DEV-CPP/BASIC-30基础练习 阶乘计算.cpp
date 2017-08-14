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
问题描述
　　输入一个正整数n，输出n!的值。
　　其中n!=1*2*3*…*n。
算法描述
　　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
　　将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
　　首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
　　输入包含一个正整数n，n<=1000。
输出格式
　　输出n!的准确值。
样例输入
10
样例输出
3628800
*/
