#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	char s[8000];
	int i,j,t=0,p,flag=0,q;
	long sum=0;
	scanf("%d",&i);
	getchar();
	gets(s);
	q=strlen(s);
//	i=q;
//	i=(q+1)/2-1;
	for(i=0;i!=(q+1)/2-1;i++)
	{
	/*	if(strchr(s,s[i])==&s[i]) 
		{
			j=i;
			while(j!=(q+1)/2-1)
			{
				swap(&s[j],&s[j+1]),j++;
			} 
			continue;
			
		}*/
		for(j=q-1-i+t;s[i]!=s[j];j--);
//		if(i<j)sum+=q-1-i-j;
		if(i==j) {t++,p=i;continue;}
		if(t==1&&q%2==0||t>=2) {flag=1;break;}
		while(j!=q-1-i+t)
		{
			swap(&s[j],&s[j+1]),j++,sum++;
		}
	}
	if(t==1&&q==4||t>=2) flag=1;
	if(flag!=1)
	{
		if(t==1)
		{
			while(p!=(q+1)/2-1)
			{
				swap(&s[p],&s[p+1]),p++,sum++;
			}
		}
//		puts(s);
		printf("%d",sum);
	}
	else printf("Impossible");
	return 0;
}
/*
��������
�������Ĵ�����һ��������ַ��������������Ҷ��ʹ����������һ���ġ�
	С������Ϊ���Ĵ����������ġ�
	���ڸ���һ����������һ���ǻ��ĵģ�����������ٵĽ�������ʹ�øô����һ�������Ļ��Ĵ���
���������Ķ����ǣ������������ڵ��ַ�
��������mamad
������һ�ν��� ad : mamda
�����ڶ��ν��� md : madma
���������ν��� ma : madam (���ģ�������)
�����ʽ
������һ����һ������N����ʾ���������ַ����ĳ���(N <= 8000)
�����ڶ�����һ���ַ���������ΪN.ֻ����Сд��ĸ
�����ʽ
����������ܣ�������ٵĽ���������
�����������Impossible
��������
5
mamad
�������
3
*/

