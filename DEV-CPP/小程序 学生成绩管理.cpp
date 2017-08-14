#include <stdio.h>
#include <string.h>
struct student
{
	char n[20];
	char c[20];
	char x[20];
	float s;
}stu[100];
int stu_amount=0;
void print_menu();
void Add_score();
void Del_score();
void Search_Name();
int main()
{ 
	print_menu();
	int choose1,choose2,choose3;
	scanf("%d",&choose1);
	while(1)
	{
		switch(choose1)
		{
			case 1:
			{
	//			display_score();
				break;
			}
			case 2:
			{
				Add_score();
				break;
			}
			case 3:
			{
//				Edit_score();
				break;
			}
			case 4:
			{
				Del_score();
				break;
			}
			/*			case 5:
			{
				do
				{
					scanf("%d",&choose2);
					switch(choose2)
					{
						case 1: 
						{
							Search_Name( ) ;
							break;
						}
					}
				}
			}*/
		}
	}
	return 0;
}
void print_menu()
{
	printf("	 ———————————————————————-\n");
	printf("	| *  *  *  *  学生成绩管理系统主菜单  *  *  * * |\n");
	printf("	| * * * * * * * * * * * * * * * * * * * * * * * |\n");
	printf("	|              请选择主菜单序号(0-6)            |\n");
	printf("	| * * * * * * * * * * * * * * * * * * * * * * * |\n");
	printf("	|                 1-----显示成绩                |\n");
	printf("	|                 2-----录入成绩                |\n");
	printf("	|                 3-----修改成绩                |\n");
	printf("	|                 4-----删除成绩                |\n");
	printf("	|                 5-----查找成绩                |\n");
	printf("	|                 6-----排序成绩                |\n");
	printf("	|                 0-----退出成绩                |\n");
	printf("	|———————————————————————-|\n");
}
void Add_score()
{
	int i,xuanze;
	char x[20];
	do 
	{
		do
		{
			printf("请輸入学生的学号:"); 
			scanf("%s",x) ;
			for(i=0;i<stu_amount;i++)
			{
				if(strcmp(x,stu[i].x)==0) break;
			}	
			if(i<stu_amount)
			{
				printf("您輸入的学号已存在, 请重新输入当前的学号…n"); 
			}
		}while(i<stu_amount);
		printf("请输入学生的姓名:");
		scanf("%s",stu[stu_amount].n);
		printf("%s",stu[stu_amount].n);
		printf("请输入学生的班级:");
		scanf("%s",stu[stu_amount].c);
		printf("%s",stu[stu_amount].c);
		printf("请输入学生的成绩:");
		scanf("%.2f",&stu[stu_amount].s);
		printf("%.2f",stu[stu_amount].s);
		strcpy(stu[stu_amount].x,x);
		printf("录入成功！\n");
		stu_amount++;
		printf("\n是否继续录入信息：是：1；否：非1；请选择：");
		scanf("%d",&xuanze);
	}while(xuanze==1);
}
void Del_score()
{
	int  i,xuanze,flag;
	char x[20];
	do
	{
		flag=-1;
		do
		{
			printf("请输入要删除学生的学号;");
			scanf("%s",x);
			for(i=0;i<stu_amount;i++)
			{	
				if(strcmp(x,stu[i].x)==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==-1)
			{
				printf("\n您輸入的学号不存在, 请重新输入学号。。。\n");
				getchar();
			}
		}while(flag==1);
		for(i=flag;i<stu_amount-1;i++) 
		{
			strcpy(stu[i].x,stu[i+1].x);
			strcpy(stu[i].n,stu[i+1].n);
			strcpy(stu[i].c,stu[i+1].c);
			stu[i].s=stu[i+1].s;
		}
		printf("删除成功!\n");
		strcpy(stu[stu_amount-1].x,"\0");
		strcpy(stu[stu_amount-1].n,"\0");
		strcpy(stu[stu_amount-1].c,"\0");
		stu[stu_amount-1].s=0;
		stu_amount--; 
		printf("\n\n是否继续删除信息:是:1；否：非1；请选择：");
		scanf("%d",&xuanze) ;
	}while(xuanze==1);
}
void Search_Name()
{
	char n[20];
	int i,flag;
	printf("请輸入要查找学生的姓名:");
	scanf("%s",n);
	flag=0;
	for(i=0;i<stu_amount;i++)
	{
		if(strcmp(n,stu[i].n)==0)
		{
			if(flag==0)
			{
				printf("学号\t姓名\t班级\t成绩\n");
			}
			printf("%s\t%s\t%s\t%.2f\n",stu[i].x,stu[i].n,stu[i].c,stu[i].s);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\n您輸入的姓名不存在!\n"); 
	}
}
/*void sort_score()
{
	int i,j;
	float t;
	char temp[20];
	case 1:
	{
		for(i=0;i<stu_amount-1;i++)
		{
			for(j=0;j<stu_amount-i-1;j++)
				if(s[j]>s[j+1])
				{
					
				}
		}
	}
	printf("学号\t姓名\t班级\t成绩\n");
	for(j=0;j<stu_amount;j++)
		printf("%s\t%s\t%s\t%.2f\n",stu[j] ,x,stu[j] ,stu_N,ame,stu[j] ,stu_Cl,ass,stu[j] ,s);
}
*/