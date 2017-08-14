#include<stdio.h>
#include<string.h>
int main()
{
	int x[4],m[4],e[4],c[4],sum[4]={0},i,j,t;
	float ave[4]={0};
	char n[4][6],k[4][6];
	for(i=1;i<=3;i++)
		scanf("%d %s %d %d %d",&x[i],n[i],&m[i],&e[i],&c[i]);
	printf("NO   Name   Maths   English   Computer   Total\n");
	for(i=1;i<=3;i++)
		sum[i]=sum[i]+m[i]+e[i]+c[i];
	for(j=1;j<=3;j++)
		for(i=1;i<=3-j;i++)
			if(sum[i]<sum[i+1])
			{
				t=x[i];
				x[i]=x[i+1];
				x[i+1]=t;
				
				strncpy(k[i],n[i],6);
				strncpy(n[i],n[i+1],6);
				strncpy(n[i+1],k[i],6);
				
				t=m[i];
				m[i]=m[i+1];
				m[i+1]=t;
				
				t=e[i];
				e[i]=e[i+1];
				e[i+1]=t;
			
				t=c[i];
				c[i]=c[i+1];
				c[i+1]=t;

				t=sum[i];
				sum[i]=sum[i+1];
				sum[i+1]=t;
			}
			
	for(i=1;i<=3;i++)
		printf("%d    %s    %d    %d    %d    %d\n",x[i],n[i],m[i],e[i],c[i],sum[i]);
	for(i=1;i<=3;i++)
		ave[1]=ave[1]+(float)m[i];
	for(i=1;i<=3;i++)
		ave[2]=ave[2]+(float)e[i];
	for(i=1;i<=3;i++)
		ave[3]=ave[3]+(float)c[i];
	for(i=1;i<=3;i++)
		ave[i]=ave[i]/3;
	printf("average of Maths:%.2f\n",ave[1]);
	printf("average of English:%.2f\n",ave[2]);
	printf("average of Computer:%.2f\n",ave[3]);		
	return 0;
}