#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	char a[30][20];
	void sort(char a[30][20],int n);
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a[i]);	
	}
	sort(a,n);
	for(i=0;i<n;i++)
	{
		puts(a[i]);	
	}
	return 0;
}
void swap(char *a,char *b)
{
	char c[10];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);

}
void sort(char a[30][20],int n)
{
	int i,j;
//	void swap(char *a,char *b);
	for(i=0;i<n-1;i++)
	{
	
		for(j=0;j<n-1-i;j++)
		{	
			if(strcmp(a[j],a[j+1])>0)
			swap(a[j],a[j+1]);
		/*	t=0;
			if(a[j][t]>a[j+1][t])
				swap(a[j],a[j+1]);
			else if(a[j][t]==a[j+1][t])
			{
				for(t=1;a[j][t]!='\0'&&a[j+1][t]!='\0';t++)
				{
					if(a[j][t]>a[j+1][t])
					{
						swap(a[j],a[j+1]);
						break;
					}
					if(a[j][t]<a[j+1][t])
						break;
				}
			
			}*/
		}
	}

}

/*
���������������ֵ�˳�����ĳ�������˵�������
��������ʽ��һ��������ݣ���һ��Ϊһ������N����ʾ������N����(N<=30)����������N����ÿ��һ������ (��������Сд��ĸ��ɣ��������ֳ���С��20)��
�������ʽ�����ֵ�˳�����е���Ա������ÿ������ռһ�С�
���������롿
5
zhangsan
liyang
wangxiao
liqing
wuhui
2
liqy
liyq
�����������liqing
                    liyang
                    wangxiao
                    wuhui
                    zhangsan
������˵����ĳ����5����,����Ϊzhangsan��liyang��wangxiao��liqing��wuhui,  
                   ���ֵ������˳��Ϊ��liqing��liyang��wangxiao��wuhui��zhangsan��
�����ֱ�׼�����⹲2�����Ե㣬ÿ�����Ե�1.0�֣���2.0�֡�
*/