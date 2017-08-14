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
【问题描述】学生信息包括：学号、姓名、数学成绩、英语成绩、计算机成绩。共有N个人(N<=10，可在程序内部定义，
                        如用#define  N 3) 的信息。要求计算每人的总成绩，并按总成绩由高到低的顺序输出所有人的信息。最后
                        输出各门课程平均成绩(保留2位小数)。（此题只按照3个学生考虑）
【输入形式】输入分N行，每行为一个学生的学号、姓名、数学成绩、英语成绩、计算机成绩信息。
【输出形式】输出为N+4行。第一行为固定字符串；第2~N+1行为按总成绩由高到低顺序输出的所有人信息；最后3行输
                        出各门课程的平均成绩。
                        要求：1、输出的第一行，每个元素的后面空3个空格，“Total”后不加空格。
                                    2、输出的第二行到第N+1行，每个元素后面空4个空格，最后一个元素，如“258”后面不加空格，
                                          且每行以回车符结束。
                                    3、输出的最后三行没有空格，每行仅以回车符结束。
                        提醒：由于本题格式比较麻烦，请同学务必按照规定输出，不然你的程序将会被判错。
【样例输入】
1001   zhang    90    80    88
1002   huang    78    80    82
1003   xiong    88    85    80
【样例输出】NO   Name   Maths   English   Computer   Total 
                        1001    zhang    90    80    88    258
                        1003    xiong    88     85    80    253
                        1002    huang    78    80    82    240
                        average of Maths:85.33
                        average of English:81.67
                        average of Computer:83.33 
【样例说明】实际上这个结果应该是下面的样子：
                        NO（3个空格）Name（3个空格） Maths（3个空格）English（3个空格）Computer（3个空格）Total
                        1001（4个空格）zhang（4个空格）90（4个空格）80（4个空格）88（4个空格）258
                        1003（4个空格）xiong（4个空格）88（4个空格）85（4个空格）80（4个空格）253
                        1002（4个空格）huang（4个空格）78（4个空格）80（4个空格）82（4个空格）240
                        average of Maths:85.33
                        average of English:81.67
                        average of Computer:83.33               
【评分标准】本题共2个测试点，通过得1.0分。
*/