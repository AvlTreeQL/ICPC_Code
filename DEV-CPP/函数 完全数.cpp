#include<stdio.h>
#include<math.h>
int main()
{
	int a;
	int r(int i);
	scanf("%d",&a);
	if(r(a)==1) printf("The number is wanquanshu");
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
/*��ȫ��������һ��������������100����һ����ȫƽ������
������268Ҳ��һ����ȫƽ������ */
