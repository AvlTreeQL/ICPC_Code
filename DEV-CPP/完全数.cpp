#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,i,t=0;
	int r(int i);
	scanf("%d %d",&m,&n);
	if(m<=0) m=0;
	for(i=m;i<=n;i++)
	{
		if(r(i)==1) 
		{
			printf("%d ",i);
			t+=1;
		}
	}
	if(t==0) printf("no");
	return 0;
}
int r(int i)
{
	int a=0,b,c;
	b=i+100;
	c=i+268;
	if((int)sqrt(b)*(int)sqrt(b)==b&&(int)sqrt(c)*(int)sqrt(c)==c) a=1;
	return a;
}
/*	
��������
��ȫ��������һ��������������100����һ����ȫƽ������������268Ҳ��һ����ȫƽ��������̳������m��n֮��������ȫ��������m��n��������n>m��
������ʽ
����һ�У���������m��n��
�����ʽ
���һ�У����m��n���������ȫ��������֮���Կո�ָ�����û�У��������no����
��������
1 10000
�������
        21 261 1581
*/