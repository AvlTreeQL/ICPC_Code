#include<stdio.h>
int main()
{
	int sum[4]={0},i,j;
	float ave[4]={0};
	struct student
	{
		int x;
		char n[6];
		int f[4];
	} a[4],b;
	for(i=1;i<=3;i++)
		scanf("%d %s %d %d %d",&a[i].x,a[i].n,&a[i].f[1],&a[i].f[2],&a[i].f[3]);
	printf("NO   Name   Maths   English   Computer   Total\n");
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			sum[i]=sum[i]+a[i].f[j];
	for(j=1;j<=3;j++)
		for(i=1;i<=3-j;i++)
			if(sum[i]<sum[i+1])
			{
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}			
	for(i=1;i<=3;i++)
		printf("%d    %s    %d    %d    %d    %d\n",a[i].x,a[i].n,a[i].f[1],a[i].f[2],a[i].f[3],sum[i]);
	for(i=1;i<=3;i++)
	{	
		for(j=1;j<=3;j++)
			ave[i]=ave[i]+(float)a[j].f[i];
		ave[i]/=3;
	}
	printf("average of Maths:%.2f\n",ave[1]);
	printf("average of English:%.2f\n",ave[2]);
	printf("average of Computer:%.2f\n",ave[3]);		
	return 0;
}
/*
������������ѧ����Ϣ������ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ�������N����(N<=10�����ڳ����ڲ����壬
                        ����#define  N 3) ����Ϣ��Ҫ�����ÿ�˵��ܳɼ��������ܳɼ��ɸߵ��͵�˳����������˵���Ϣ�����
                        ������ſγ�ƽ���ɼ�(����2λС��)��������ֻ����3��ѧ�����ǣ�
��������ʽ�������N�У�ÿ��Ϊһ��ѧ����ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ���Ϣ��
�������ʽ�����ΪN+4�С���һ��Ϊ�̶��ַ�������2~N+1��Ϊ���ܳɼ��ɸߵ���˳���������������Ϣ�����3����
                        �����ſγ̵�ƽ���ɼ���
                        Ҫ��1������ĵ�һ�У�ÿ��Ԫ�صĺ����3���ո񣬡�Total���󲻼ӿո�
                                    2������ĵڶ��е���N+1�У�ÿ��Ԫ�غ����4���ո����һ��Ԫ�أ��硰258�����治�ӿո�
                                          ��ÿ���Իس���������
                                    3��������������û�пո�ÿ�н��Իس���������
                        ���ѣ����ڱ����ʽ�Ƚ��鷳����ͬѧ��ذ��չ涨�������Ȼ��ĳ��򽫻ᱻ�д�
���������롿
1001   zhang    90    80    88
1002   huang    78    80    82
1003   xiong    88    85    80
�����������NO   Name   Maths   English   Computer   Total 
                        1001    zhang    90    80    88    258
                        1003    xiong    88     85    80    253
                        1002    huang    78    80    82    240
                        average of Maths:85.33
                        average of English:81.67
                        average of Computer:83.33 
������˵����ʵ����������Ӧ������������ӣ�
                        NO��3���ո�Name��3���ո� Maths��3���ո�English��3���ո�Computer��3���ո�Total
                        1001��4���ո�zhang��4���ո�90��4���ո�80��4���ո�88��4���ո�258
                        1003��4���ո�xiong��4���ո�88��4���ո�85��4���ո�80��4���ո�253
                        1002��4���ո�huang��4���ո�78��4���ո�80��4���ո�82��4���ո�240
                        average of Maths:85.33
                        average of English:81.67
                        average of Computer:83.33               
�����ֱ�׼�����⹲2�����Ե㣬ͨ����1.0�֡�
*/