/*������������NֻС����(1 < N < 100)��ÿֻ��ͷ�ϴ���һ������ɫ��ñ�Ӳ�����һ����š����ڳƳ�ÿֻ�����������Ҫ���հ��������Ӵ�С��˳��������ǵı�ź�ͷ��ñ�ӵ���ɫ������ǳ���Ϊ5���ַ������磺��W-101��,��T-002���ȣ�ñ�ӵ���ɫ�á�red��,��blue�����ַ�������ʾ����ͬ��С������Դ���ͬ��ɫ��ñ�ӡ������������������ʾ��
��������ʽ�������������ı��ļ�IN.TXT�У����ݸ�ʽ�ǣ���һ��Ϊһ������N����ʾС�������Ŀ����������N�У�ÿ����һֻ�������Ϣ����һ��Ϊ��ţ��ڶ���Ϊ������100������������ʾ�����������������Ϊ��ʾ�����ñ����ɫ���ַ������䳤�Ȳ�����10���ַ���
�������ʽ�����հ��������ĴӴ�С˳���������ı�ź�ñ����ɫ���ı��ļ�OUT.TXT�С�
���������롿IN.TXT�ļ�
                   3
                   T-001 30 red
                   W-001 50 blue
                   T-101 40 green                      
�����������OUT.TXT�ļ�
                   W-001 blue
                   T-101 green
                   T-001 red   */
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *p;
	struct mouse
	{
		char name[6];
		int wight;
		char color[10];
	}mou[101],t;
	int n,i,j;
	scanf("%d",&n);
	if((p=fopen("IN.TXT","w"))==NULL)
	{printf("cannot open this file1\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		scanf("%s%d%s",t.name,&t.wight,t.color);
		fprintf(p,"%s %d %s\n",t.name,t.wight,t.color);
	}
	fclose(p);
	if((p=fopen("IN.TXT","r"))==NULL)
	{printf("cannot open this file2\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fscanf(p,"%s%d%s",mou[i].name,&mou[i].wight,mou[i].color);
		//printf("%s %d %s\n",mou[i].name,mou[i].wight,mou[i].color);
	}
	fclose(p);
	for(i=1;i<n;i++)
		for(j=1;j<=n-i;j++)
			if(mou[j].wight<mou[j+1].wight)
			{
				t=mou[j];
				mou[j]=mou[j+1];
				mou[j+1]=t;
			}
	if((p=fopen("OUT.TXT","w"))==NULL)
	{printf("cannot open this file3\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fwrite(&mou[i],sizeof(struct mouse),1,p);
	}
	fclose(p);
	if((p=fopen("OUT.TXT","r"))==NULL)
	{printf("cannot open this file4\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fread(&t,sizeof(struct mouse),1,p);
		printf("%s %s\n",t.name,t.color);
	}
	fclose(p);
	return 0;
}