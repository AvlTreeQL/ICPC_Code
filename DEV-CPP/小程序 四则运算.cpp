#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	printf("	***************��λ���ڵ�Сѧ�������������ϵͳ***************\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                1------------------�ӷ�����                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                2------------------��������                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                3------------------�˷�����                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                4------------------��������                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	*                0------------------�˳�����                 *\n");
	printf("	*                                                            *\n");
	printf("	*                                                            *\n");
	printf("	**************************************************************\n");
	int a,b,s=0,n,num1,num2,i;
	srand(time(0));
	scanf("%d",&a);
	switch(a)
	{
		 case 1:printf("\n	�����������Ŀ����:");
				scanf("%d",&n);
				printf("	���ܹ�����%d���ӷ���Ŀ��������ÿ����Ŀ�ĺ��������Լ��Ĵ�\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	��Ŀ:%d+%d=",num1,num2);
					scanf("%d",&b);
					if (num1+num2==b)
					{
						printf("	��ȫ��ȷ!\n");
						s+=1;
					}
					else
					{	
						printf("	����,%d+%d=%d, ������Ĵ���%d\n",num1,num2,num1+num2,b);
					}
				}
				printf("	���ܹ�����%d���ӷ���Ŀ������Ϊ100 �֣���������%d��,�÷�Ϊ%.2f\n",n,s,s*100.0/n);
				break;
		 case 2:printf("\n	�����������Ŀ����:");
				scanf("%d",&n);
				printf("	���ܹ�����%d��������Ŀ��������ÿ����Ŀ�ĺ��������Լ��Ĵ�\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	��Ŀ:%d-%d=",num1,num2);
					scanf("%d",&b);
					if (num1-num2==b)
					{
						printf("	��ȫ��ȷ!\n");
						s+=1;
					}
					else
					{	
						printf("	����,%d-%d=%d, ������Ĵ���%d\n",num1,num2,num1-num2,b);
					}
				}
				printf("	���ܹ�����%d��������Ŀ������Ϊ100 �֣���������%d��,�÷�Ϊ%.2f\n",n,s,s*100.0/n);
				break;
		 case 3:printf("\n	�����������Ŀ����:");
				scanf("%d",&n);
				printf("	���ܹ�����%d���˷���Ŀ��������ÿ����Ŀ�ĺ��������Լ��Ĵ�\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	��Ŀ:%d*%d=",num1,num2);
					scanf("%d",&b);
					if (num1*num2==b)
					{
						printf("	��ȫ��ȷ!\n");
						s+=1;
					}
					else
					{	
						printf("	����,%d*%d=%d, ������Ĵ���%d\n",num1,num2,num1*num2,b);
					}
				}
				printf("	���ܹ�����%d���˷���Ŀ������Ϊ100 �֣���������%d��,�÷�Ϊ%.2f\n",n,s,s*100.0/n);
				break;
		 case 4:printf("\n	�����������Ŀ����:");
				scanf("%d",&n);
				printf("	���ܹ�����%d��������Ŀ��������ÿ����Ŀ�ĺ��������Լ��Ĵ�\n",n);
				for(i=1;i<=n;i++)
				{
					num1=rand()%999+1; 
					num2=rand()%999+1; 
					printf("	��Ŀ:%d/%d=",num1,num2);
					scanf("%d",&b);
					if (num1/num2==b)
					{
						printf("	��ȫ��ȷ!\n");
						s+=1;
					}
					else
					{	
						printf("	����,%d/%d=%d, ������Ĵ���%d\n",num1,num2,num1/num2,b);
					}
				}
				printf("	���ܹ�����%d��������Ŀ������Ϊ100 �֣���������%d��,�÷�Ϊ%.2f\n",n,s,s*100.0/n);
				break;
		 case 0:break;
	}
	return 0;
}