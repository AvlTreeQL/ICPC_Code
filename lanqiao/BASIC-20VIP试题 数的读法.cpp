/*
��������
����Tom�������ڸ��о�������һ�Ź��ڻ���Ŀγ̣���һ������������Ϊͷ�ۣ�һ��Ⱦɫ�����г�ǧ���������ԣ����Ǵ�0��ʼ��ţ��������򣬼�ǧ���������ڡ�
��������˵���ڶ�ѧ�������1234567009��λ���ϵļ��ʱ���⿴�������Ǻ���׼ȷ��������ġ�
�������ԣ������е���Ҫһ��ϵͳ��Ȼ��������12 3456 7009ʱ���������Ӧ�����
����ʮ������ǧ�İ���ʮ������ǧ���
�����ú���ƴ����ʾΪ
����shi er yi san qian si bai wu shi liu wan qi qian ling jiu
����������ֻ��Ҫ������Ϳ����ˡ�
������������ǰ����������һ��ϵͳ������һ�����������ִ���������������Ķ�д�Ĺ淶תΪ����ƴ���ִ������ڵ�����������һ���ո���񿪡�
����ע������ϸ��չ淶������˵��10010��������yi wan ling yi shi�������ǡ�yi wan ling shi������100000��������shi wan�������ǡ�yi shi wan������2000��������er qian�������ǡ�liang qian����
�����ʽ
������һ�����ִ�����ֵ��С������2,000,000,000��
�����ʽ
������һ����СдӢ����ĸ�����źͿո���ɵ��ַ�������ʾ������Ӣ�Ķ�����
��������
1234567009
�������
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
*/
#include<stdio.h>
#include<string.h>
void print(char a[],int l)
{
	char b[][5]={"","shi","bai","qian","wan"},c[][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int i;
	
	for(i=0;i<l;i++)
	{
		if(l==4&&a[0]=='0'&&a[1]=='0'&&a[2]=='0'&&a[3]=='0') break;
		if(l==4&&a[0]!='0'&&a[1]=='0'&&a[2]=='0'&&a[3]=='0')
		{
			printf("%s ",c[a[i]-'0']);
			printf("%s ",b[l-i-1]);
			break;
		}
		
		if(a[i]!='0'||i!=l-1)
		{ 	
			if(a[2]=='0'&&a[3]=='0'&&(i==2||i==3))  continue;
			if(a[i]=='0'&&a[i-1]=='0') continue;
			if(l==2&&a[0]=='1'&&i==0) 
			{
				printf("shi ");
				continue;
			}
			printf("%s ",c[a[i]-'0']);
		
		}
		if(a[i]!='0'&&i!=l-1) printf("%s ",b[l-i-1]);
	}
}
int main()
{
	char a[15],b[5],c[5];
	gets(a);
	int i,j,t,l;
	l=strlen(a);
	if(l>=9)
	{
		strcpy(c,&a[l-4]);
		a[l-4]='\0';
		strcpy(b,&a[l-8]);
		a[l-8]='\0';
		print(a,l-8);
		printf("yi ");
		print(b,4);
		printf("wan ");
		print(c,4);
	}
	else if(l>=5)
	{
		strcpy(b,&a[l-4]);
		a[l-4]='\0';
		print(a,l-4);
		printf("wan ");
		print(b,4);
	}
	else 
	{
		print(a,l);
	}
	
	return 0;
}



