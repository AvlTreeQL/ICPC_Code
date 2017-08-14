/*问题描述
有5个学生，每个学生有3门课的成绩，从键盘输入以上数据（包括学生号、姓名、三门课成绩），计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件stud.dat中。然后从stud.dat文件中读出每个学生信息显示出来，包括（学生号、姓名、三门课成绩、平均成绩）。
输入形式
输入五行，只包括5个学生的数据信息。
输出形式
输出五行，给出每个学生的信息，包括学生号、姓名、三门课成绩、平均成绩。每行数据输出的格式为"%s %s %d %d %d %.2f\n"
样例输入
001 zhang 70 80 90
002 li 89 90 100
003 zhe 60 70 80
004 lei 80 90 100
005 fei 65 75 85
 
样例输出
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