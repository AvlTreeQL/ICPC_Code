/*������������ѧ���ɼ�����ÿ��ѧ�������ݰ���ѧ�š�������3�ſεĳɼ������ݱ������ļ���(�ڴ���ֻ����һ��ѧ������Ϣ�������д���ļ�)���ֱ������ɸ�����ʵ�����¸�����������ѡ��ִ����Ӧ���ܡ�
                       1) ����ѧ���ɼ���
                       2) ����ѧ�Ż��������ҵ���ѧ������Ϣ��
                       3) ����ѧ�Ż��������޸�ĳѧ������Ϣ��
                       4) �ҳ�ĳ�ſγ̲������ѧ�����������ѧ�źͲ�����γ̵ĳɼ����������ڣ����ӡno��
                       5) ��������ѧ���ĸ���ƽ���ɼ�����ƽ���ɼ���
��������ʽ����һ��Ϊһ������N����ʾѧ��������������N����ÿ�а���5�����ݣ�ѧ��(�ַ���)������(�ַ���)�� 3�ſεĳɼ�(�ɼ�Ϊ����)����N+2��Ϊһ���ַ�������ʾҪ���ҵ�ѧ��ѧ�ţ���N+3��Ϊ6������(������ѧ�š�������3�ſεĳɼ�)����ʾҪ�޸���Ϣ��ѧ�������Լ����޸ĵĸ�ѧ����Ϣ����N+4��Ϊ����(1��2��3)����ʾҪ���ҵ��ǵڼ��ſγ̡�
�������ʽ����1��Ϊ����ѧ�ŵ�ѧ����Ϣ����2��Ϊ�����������Ѿ��޸ĵ�ѧ����Ϣ����3��Ϊָ���γ��в�����ѧ����ѧ���Լ�������γ̵ĳɼ�(����֮���ɿո�ָ�)����4��Ϊ����ѧ���ĸ���ƽ���ɼ�����ƽ���ɼ�(����֮���ɿո�ָ���������λ��Ч����)��
���������롿3
                    070001 ZhangLi   90 80 85
                    070002 WangHua 86 55 90
                    070003 ChenHai   58 42 84
                    070002
                    ChenHai 070003 ChenHai 58 42 90
                    2
�����������070002 WangHua  86  55  90
                    070003 ChenHai 58  42  90
                    070002 55 070003 42
                    78.00 59.00 88.33 75.11*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp,*p;
	struct student
	{
		char number[20];
		char name[20];
		int grade[4];
	}stu;
	char a[20];
	double sum=0;
	double per[4]={0};
	int n,j,i,m,leap=1;
	scanf("%d",&n);
	if((fp=fopen("test.txt","w"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		scanf("%s%s%d%d%d",stu.number,stu.name,&stu.grade[1],&stu.grade[2],&stu.grade[3]);
		fwrite(&stu,sizeof(struct student),1,fp);
	}
	fclose(fp);
	if((fp=fopen("test.txt","r"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	scanf("%s",a);
	for(i=1;i<=n;i++)
	{
		fread(&stu,sizeof(struct student),1,fp);
		if((strcmp(a,stu.number)==0)||(strcmp(a,stu.name)==0))
		{
			printf("%s %s %d %d %d\n",stu.number,stu.name,stu.grade[1],stu.grade[2],stu.grade[3]);
			break;
		}
	}
	if((p=fopen("text.txt","w"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	scanf("%s",a);
	rewind(fp);
	for(i=1;i<=n;i++)
	{
		fread(&stu,sizeof(struct student),1,fp);
		if((strcmp(a,stu.number)==0)||(strcmp(a,stu.name)==0))
		{
			scanf("%s%s%d%d%d",stu.number,stu.name,&stu.grade[1],&stu.grade[2],&stu.grade[3]);
			printf("%s %s %d %d %d\n",stu.number,stu.name,stu.grade[1],stu.grade[2],stu.grade[3]);
		}
		fwrite(&stu,sizeof(struct student),1,p);
	}
	fclose(fp);
	fclose(p);
	if((p=fopen("text.txt","r"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	scanf("%d",&m);
	for(i=1;i<=n;i++)
	{
		fread(&stu,sizeof(struct student),1,p);
		for(j=1;j<=3;j++)
		{
			sum=sum+stu.grade[j];
			per[j]=per[j]+stu.grade[j];
		}
		if(stu.grade[m]<60)
		{
			leap=0;
			printf("%s %d ",stu.number,stu.grade[m]);
		}
	}
	if(leap) printf("no");
	printf("\n");
	sum=sum/(n*3.0);
	for(j=1;j<=3;j++)
	{
		per[j]=per[j]/(n*1.0);
		printf("%.2lf ",per[j]);
	}
	printf("%.2lf\n",sum);
	fclose(p);
	return 0;
}