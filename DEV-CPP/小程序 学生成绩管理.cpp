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
	printf("	 ����������������������������������������������-\n");
	printf("	| *  *  *  *  ѧ���ɼ�����ϵͳ���˵�  *  *  * * |\n");
	printf("	| * * * * * * * * * * * * * * * * * * * * * * * |\n");
	printf("	|              ��ѡ�����˵����(0-6)            |\n");
	printf("	| * * * * * * * * * * * * * * * * * * * * * * * |\n");
	printf("	|                 1-----��ʾ�ɼ�                |\n");
	printf("	|                 2-----¼��ɼ�                |\n");
	printf("	|                 3-----�޸ĳɼ�                |\n");
	printf("	|                 4-----ɾ���ɼ�                |\n");
	printf("	|                 5-----���ҳɼ�                |\n");
	printf("	|                 6-----����ɼ�                |\n");
	printf("	|                 0-----�˳��ɼ�                |\n");
	printf("	|����������������������������������������������-|\n");
}
void Add_score()
{
	int i,xuanze;
	char x[20];
	do 
	{
		do
		{
			printf("��ݔ��ѧ����ѧ��:"); 
			scanf("%s",x) ;
			for(i=0;i<stu_amount;i++)
			{
				if(strcmp(x,stu[i].x)==0) break;
			}	
			if(i<stu_amount)
			{
				printf("��ݔ���ѧ���Ѵ���, ���������뵱ǰ��ѧ�š�n"); 
			}
		}while(i<stu_amount);
		printf("������ѧ��������:");
		scanf("%s",stu[stu_amount].n);
		printf("%s",stu[stu_amount].n);
		printf("������ѧ���İ༶:");
		scanf("%s",stu[stu_amount].c);
		printf("%s",stu[stu_amount].c);
		printf("������ѧ���ĳɼ�:");
		scanf("%.2f",&stu[stu_amount].s);
		printf("%.2f",stu[stu_amount].s);
		strcpy(stu[stu_amount].x,x);
		printf("¼��ɹ���\n");
		stu_amount++;
		printf("\n�Ƿ����¼����Ϣ���ǣ�1���񣺷�1����ѡ��");
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
			printf("������Ҫɾ��ѧ����ѧ��;");
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
				printf("\n��ݔ���ѧ�Ų�����, ����������ѧ�š�����\n");
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
		printf("ɾ���ɹ�!\n");
		strcpy(stu[stu_amount-1].x,"\0");
		strcpy(stu[stu_amount-1].n,"\0");
		strcpy(stu[stu_amount-1].c,"\0");
		stu[stu_amount-1].s=0;
		stu_amount--; 
		printf("\n\n�Ƿ����ɾ����Ϣ:��:1���񣺷�1����ѡ��");
		scanf("%d",&xuanze) ;
	}while(xuanze==1);
}
void Search_Name()
{
	char n[20];
	int i,flag;
	printf("��ݔ��Ҫ����ѧ��������:");
	scanf("%s",n);
	flag=0;
	for(i=0;i<stu_amount;i++)
	{
		if(strcmp(n,stu[i].n)==0)
		{
			if(flag==0)
			{
				printf("ѧ��\t����\t�༶\t�ɼ�\n");
			}
			printf("%s\t%s\t%s\t%.2f\n",stu[i].x,stu[i].n,stu[i].c,stu[i].s);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\n��ݔ�������������!\n"); 
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
	printf("ѧ��\t����\t�༶\t�ɼ�\n");
	for(j=0;j<stu_amount;j++)
		printf("%s\t%s\t%s\t%.2f\n",stu[j] ,x,stu[j] ,stu_N,ame,stu[j] ,stu_Cl,ass,stu[j] ,s);
}
*/