#include<stdio.h>
#include<stdlib.h>

int main()
{
	void fun(int n);
	int i;
	for(i=0;i<32;i++)
		fun(i);
	return 0;
} 
void fun(int n)
{
	char a[6]={0};
	int i=4;
	while(n)
	{
		a[i--]=n%2+'0';
		n/=2;
	} 
	puts(a);
}
/*
void trans(int n)//10����ת����b����	
{	int i,j;
	for(i=0;n!=0;i++)
	{	
		o[i]=n%b+'0';
		n=n/b;
	}
}

/*char *fun(int n)
{
	char *p,*temp;
	p=(char *)malloc(sizeof(char)*5);
	temp=p;
	while(n)
	{
		*(p++)=n%2;
		n/=2;
	} 
	*p='\0';
	return temp;
}
/*
��������
���ڳ���Ϊ5λ��һ��01����ÿһλ��������0��1��һ����32�ֿ��ܡ����ǵ�ǰ�����ǣ�
00000
00001
00010
00011
00100
�밴��С�����˳�������32��01����
�����ʽ
������û�����롣
�����ʽ
���32�У�����С�����˳��ÿ��һ������Ϊ5��01����
�������
00000
00001
00010
00011
<���²���ʡ��>
*/
