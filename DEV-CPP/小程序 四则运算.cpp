#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	printf("	***************三位数内的小学生四则运算测试系统***************\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                1------------------加法测试                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                2------------------减法测试                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                3------------------乘法测试                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                4------------------除法测试                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                0------------------退出测试                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	**************************************************************\n");
	int a,b,s=0,n,num1,num2,i;
	srand(time(0));
	scanf("%d",&a);
	switch(a)
	{
		 case 1:printf("\n	请输入测试题目数量:");
				scanf("%d",&n);
				printf("	你总共测试%d道加法题目，请你在每道题目的后面输入自己的答案\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	题目:%d+%d=",num1,num2);
					scanf("%d",&b);
					if (num1+num2==b)
					{
						printf("	完全正确!\n");
						s+=1;
					}
					else
					{	
						printf("	错误,%d+%d=%d, 你给出的答案是%d\n",num1,num2,num1+num2,b);
					}
				}
				printf("	你总共做了%d道加法题目，满分为100 分，你做对了%d道,得分为%.2f\n",n,s,s*100.0/n);
				break;
		 case 2:printf("\n	请输入测试题目数量:");
				scanf("%d",&n);
				printf("	你总共测试%d道减法题目，请你在每道题目的后面输入自己的答案\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	题目:%d-%d=",num1,num2);
					scanf("%d",&b);
					if (num1-num2==b)
					{
						printf("	完全正确!\n");
						s+=1;
					}
					else
					{	
						printf("	错误,%d-%d=%d, 你给出的答案是%d\n",num1,num2,num1-num2,b);
					}
				}
				printf("	你总共做了%d道减法题目，满分为100 分，你做对了%d道,得分为%.2f\n",n,s,s*100.0/n);
				break;
		 case 3:printf("\n	请输入测试题目数量:");
				scanf("%d",&n);
				printf("	你总共测试%d道乘法题目，请你在每道题目的后面输入自己的答案\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	题目:%d*%d=",num1,num2);
					scanf("%d",&b);
					if (num1*num2==b)
					{
						printf("	完全正确!\n");
						s+=1;
					}
					else
					{	
						printf("	错误,%d*%d=%d, 你给出的答案是%d\n",num1,num2,num1*num2,b);
					}
				}
				printf("	你总共做了%d道乘法题目，满分为100 分，你做对了%d道,得分为%.2f\n",n,s,s*100.0/n);
				break;
		 case 4:printf("\n	请输入测试题目数量:");
				scanf("%d",&n);
				printf("	你总共测试%d道除法题目，请你在每道题目的后面输入自己的答案\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	题目:%d/%d=",num1,num2);
					scanf("%d",&b);
					if (num1/num2==b)
					{
						printf("	完全正确!\n");
						s+=1;
					}
					else
					{	
						printf("	错误,%d/%d=%d, 你给出的答案是%d\n",num1,num2,num1/num2,b);
					}
				}
				printf("	你总共做了%d道除法题目，满分为100 分，你做对了%d道,得分为%.2f\n",n,s,s*100.0/n);
				break;
		 case 0:break;
	}
	return 0;
}