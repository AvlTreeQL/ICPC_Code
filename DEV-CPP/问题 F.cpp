#include<stdio.h>
#include<string.h>
void fun(char a[1000],int n,char b[100][100]);
int main()
{
	char a[1000],b[100][100];
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)	
		gets(b[i]);
	gets(a);
	fun(a,n,b);
	puts(a);
	return 0;
}
void fun(char a[],char b[])
{
	int i,j,t,p,k,o=0;
	int f(char a,char b);
		for(i=0;a[i]!='\0';i++)
		{	k=i;
			for(j=0;b[j]!='\0';k++,j++)//�ҵ�b[]��Ӧ�ַ����� a[] ��λ��
			{	
				if(f(a[k],b[j])==1) 
				{	
					p=1;	
				}
				else
				{
					p=0;
					break;
				}
			}		 
			if(p==1)//��Ҫ�滻���ַ�  ���ַ��� c[] ���� d[80]
			{
				d[o++]=a[i];
				i=i+strlen(b)-1;
				for(t=1;t<strlen(b);t++)
					d[o++]='*';
				
			} 
			else	// ����Ҫ�滻���ַ� ��ԭ�����ַ���a[] ���� d[80]
			{
				d[o++]=a[i];
			}
		}
		d[o]='\0';
}
int f(char a,char b)
{
	if(a==b||a+32==b||a-32==b||b+32==a||b-32==a) return 1;
	else return 0;
}
/*
void fun(char a[1000],int n,char b[100][100])
{
	int i,j;
	char *p;
	for(i=0;i<n;i++)
	{
		while(strstr(a,b[i]))
		{	p=strstr(a,b[i]);
			j=0;
			while(b[i][++j]!='\0')
			{
				*(++p)='*';
			}
		}
	}
}

/*
��Ŀ����
Ϊ����������������һЩ���дʻ㣬BBS�������в��ܳ���ĳЩΥ�����
�������ϵͳ���Ϊ�ɹ���Ա�������ɵ�Υ���ʻ㣬���������е�Υ���ʻ㣬ϵͳֻ��ʾ��һ���ַ��������ַ�ȫ����*���档
ע�����Υ���ʻ�ʱ�ǲ����Ǵ�Сд�ģ����޸�ʱ��Ҫ������Сд��
����love��Υ���ʻ㣬��Love��love����Υ������������е�love�����Ϊl***����Love���L***��
���ھͿ��������
����
��������ֻ��һ�飬��һ��Ϊһ��������n��n<=1000������������n�У�ÿ����һ��Ӣ�ĵ��ʣ������ɸ�Ӣ����ĸ��ɣ������ո񣨵��ʳ��Ȳ�����20����

�����������ɶ���Ҫ��������֣������ļ�����Ϊֹ���ַ�����������10000����

���
������������֣�����Υ������������ֺ͸�ʽ���䡣

��������
2
Love
sylu
I love ShenYang,and love sylu more
�������
I l*** ShenYang,and l*** s*** more
*/