#include<stdio.h>
int main()
{
	int i,n,d=0,x=0,s=0,k=0,o=0;
	char c;
	scanf("%d",&n);
	for(i=0;i<=n;)
	{
		scanf("%c",&c);
		if(c=='\n') 
			i++;
		else
			if(c>='A'&&c<='Z') 
				d++;
			else
				if(c>='a'&&c<='z') 
					x++;
				else
					if(c>='0'&&c<='9') 
						s++;
					else
						if(c==' ') 
							k++;
						else o++;
 	}
	printf("%d %d %d %d %d",d,x,s,k,o);
	return 0;
}
/*	
��������
��һƪ���£�����n��n������20�������֣�ÿ�������ɸ��ַ���ɣ��ַ�����������80����Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д��ĸ��Сд��ĸ�����֡��ո��Լ������ַ��ĸ�����
������ʽ
����n+1�С�
��һ����������n��
�ڶ��е�n+1�зֱ�����n���ַ�����
�����ʽ
���һ�У�������ƪ����Ӣ�Ĵ�д��ĸ��Сд��ĸ�����֡��ո��Լ������ַ��ĸ�����������ֵ�Կո�ָ���
��������
4
1.I 'm an office worker.   2.I work for the government.
3.I 'm happy to meet you.  4.I like your sense of humor. 
5.I 'm glad to see you again.  6.I 'll call you.
7.I feel like sleeping/ taking a walk.  8.I want something to eat.
�������
8 142 8 48 21
*/