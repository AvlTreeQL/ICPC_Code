/*
��������������һ��Ӣ���������ַ����ø������ַ����滻��
��������ʽ������������У�ÿһ��Ϊһ��Ӣ�����£����Ȳ�����80�����Ժ�ÿ�а���2���ַ��������Ȳ�����20����֮���ɿո�ָ�����һ����Ϊԭ�����ڶ�����Ϊ�滻����������0 0������ʱ��ʾ������������Ҵ��в��账��ע�⣺������Ҫ����ԭ�����滻���ĳ��Ȳ�ͬ��������������1��ԭ���ĳ��ȴ����滻������ԭ��Ϊare ���滻��Ϊis�����2��ԭ���ĳ��ȵ����滻������ԭ��Ϊh ���滻��ΪH�����3��ԭ���ĳ���С�滻������ԭ��Ϊyes ���滻��Ϊyour��
�������ʽ������滻������¡�
���������롿
hello how are yes.
h H
es ou
0 0
�����������Hello How are you.
�����ֱ�׼�����⹲4�����Ե㣬ÿ�����Ե�0.25�֣��ܷ�1.0�֡�
hello how are yes.
are a
how abc
0 0
*/
#include<stdio.h>
#include<string.h>
void change(char str[81],char a[21],char b[21]);
int main()
{
	char str[81],a[21],b[21];
	gets(str);
	do
	{
		scanf("%s%s",a,b);
		if(a[0]!='0'&&b[0]!='0') change(str,a,b);
	}while(a[0]!='0'&&b[0]!='0');
	puts(str);
	return 0;
}
void change(char str[81],char a[21],char b[21])
{
	char *p,str1[81]={0};
	while(1)
	{
		p=strstr(str,a);
		if(p==NULL) break;
		*p='\0';
		strcat(str1,str);
		strcat(str1,b);
		strcat(str1,p+strlen(a));
		strcpy(str,str1);
		str1[0]='\0';
	}
 /*	
	char *p,str1[81]={0};
	int i,t=0;
	p=strstr(str,a);
	for(i=0;str[i]!='\0';i++)
	{
		if(&str[i]==p) strcat(str1,b),t=strlen(str1),i+=strlen(a);
		str1[t++]=str[i];
	}
	str1[t]='\0';
	strcpy(str,str1);
*/
}	