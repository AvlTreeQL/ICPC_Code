/*��������
��5��ѧ����ÿ��ѧ����3�ſεĳɼ����Ӽ��������������ݣ�����ѧ���š����������ſγɼ����������ƽ���ɼ�����ԭ�����ݺͼ������ƽ����������ڴ����ļ�stud.dat�С�Ȼ���stud.dat�ļ��ж���ÿ��ѧ����Ϣ��ʾ������������ѧ���š����������ſγɼ���ƽ���ɼ�����
������ʽ
�������У�ֻ����5��ѧ����������Ϣ��
�����ʽ
������У�����ÿ��ѧ������Ϣ������ѧ���š����������ſγɼ���ƽ���ɼ���ÿ����������ĸ�ʽΪ"%s %s %d %d %d %.2f\n"
��������
001 zhang 70 80 90
002 li 89 90 100
003 zhe 60 70 80
004 lei 80 90 100
005 fei 65 75 85
 
�������
001 zhang 70 80 90 80.00
002 li 89 90 100 93.00
003 zhe 60 70 80 70.00
004 lei 80 90 100 90.00
005 fei 65 75 85 75.00*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	struct student
	{
		char number[10];
		char name[21];
		int grade1;
		int grade2;
		int grade3;
		double per;
	}stu[6],ss;
	int i;
	for(i=1;i<=5;i++)
	{
		scanf("%s%s%d%d%d",stu[i].number,stu[i].name,&stu[i].grade1,&stu[i].grade2,&stu[i].grade3);
		stu[i].per=(stu[i].grade1+stu[i].grade2+stu[i].grade3)/3.0;
	}
	if((fp=fopen("stud.dat","w"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	for(i=1;i<=5;i++)
	{
		fwrite(&stu[i],sizeof(struct student),1,fp);
	}
	fclose(fp);
	if((fp=fopen("stud.dat","r"))==NULL)
	{printf("cannot open this file\n");exit(0);}
	for(i=1;i<=5;i++)
	{
		fread(&ss,sizeof(struct student),1,fp);
		printf("%s %s %d %d %d %.2lf\n",ss.number,ss.name,ss.grade1,ss.grade2,ss.grade3,ss.per);
	}
	fclose(fp);
	return 0;
}