#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	char a[100][100],b[100][100];
	int stringcmp(char *str1 ,char *str2 );
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s",a[i],b[i]);
	}
	for(i=0;i<n;i++)
		printf("%d\n",stringcmp(a[i],b[i]));
	return 0;
}
int stringcmp(char *str1 ,char *str2 )
{
	int i;
	if(strcmp(str1,str2)==0)
	{
		return 0;
	}
	else
	{
		for(i=0;str1[i]!='\0'||str2[i]!='\0';i++)
			if(str1[i]!=str2[i]) 
			{	
				return str1[i]-str2[i];
				break;	
			}
	} 

}
/*
���������������ַ����ȽϹ��̶Ը����������ַ������бȽϣ����������Ϊ0������������Ϊ��Ӧ�����ַ��Ĳ��Ҫ��ʵ�ֶԸ����ַ����ıȽϡ�Ҫ��������ú���ʵ�������ַ����ıȽϡ�int stringcmp(char *str1 ,char *str2 )
��������ʽ����һ��Ϊһ������N����ʾ�������ݵ���������������N����ÿ�а��������ַ������ַ���֮���ɿո�ָ���
�������ʽ�������N�У�ÿ��Ϊ��Ӧ����һ�е������ַ����ıȽϽ����
���������롿
3
Happy Help
Help Help
Help Happy
�����������- 4
                    0
                    4
������˵��������3���ַ�������1��Ϊ��Happy����"Help",��2��Ϊ��Help���͡�Help������3��Ϊ��Help���͡�Happy�����ȽϽ���ֱ�Ϊ-4��0��4��
�����ֱ�׼�����⹲2�����Ե㣬ÿ�����Ե�1.0�֣���2.0�֡�
*/