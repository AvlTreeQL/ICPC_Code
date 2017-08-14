/*【问题描述】学生成绩管理，每个学生的数据包括学号、姓名、3门课的成绩，数据保存在文件中(内存中只保留一个学生的信息，处理后写回文件)。分别用若干个函数实现如下各操作，根据选择执行相应功能。
                       1) 输入学生成绩；
                       2) 给出学号或姓名，找到该学生的信息。
                       3) 给出学号或姓名，修改某学生的信息。
                       4) 找出某门课程不及格的学生，并输出其学号和不及格课程的成绩；若不存在，则打印no。
                       5) 给出所有学生的各科平均成绩和总平均成绩。
【输入形式】第一行为一个整数N，表示学生数；接下来的N行中每行包含5个数据：学号(字符串)、姓名(字符串)、 3门课的成绩(成绩为整数)；第N+2行为一个字符串，表示要查找的学生学号；第N+3行为6个数据(姓名、学号、姓名、3门课的成绩)，表示要修改信息的学生姓名以及欲修改的该学生信息；第N+4行为数字(1、2或3)，表示要查找的是第几门课程。
【输出形式】第1行为给定学号的学生信息；第2行为给定姓名的已经修改的学生信息；第3行为指定课程中不及格学生的学号以及不及格课程的成绩(各数之间由空格分隔)；第4行为所有学生的各科平均成绩和总平均成绩(各数之间由空格分隔，保留两位有效数字)。
【样例输入】3
                    070001 ZhangLi   90 80 85
                    070002 WangHua 86 55 90
                    070003 ChenHai   58 42 84
                    070002
                    ChenHai 070003 ChenHai 58 42 90
                    2
【样例输出】070002 WangHua  86  55  90
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