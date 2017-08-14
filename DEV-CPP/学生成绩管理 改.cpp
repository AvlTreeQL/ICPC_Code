/*
【问题描述】用结构数组实现学生成绩统计各功能。
                        某班有N(N<=30)个学生，共开设5门课程，分别用三个函数实现如下功能：
                          ⑴ 求第一门课程的平均分；
                          ⑵ 找出有2门及2门以上不及格的学生，并输出其学号；
                          ⑶ 找出平均成绩在90分及以上的学生，输出他们的学号。
【输入形式】第一行为一个整数N，表示本班共N个人，接下来的N行中每行包含一个学生的信息，包括学号(长度
                        小于11的字符串)、课程1成绩、课程2成绩、课程3成绩、课程4成绩、课程5成绩。成绩均为整数。
【输出形式】输出共三行：
                        第一行为本班第一门课程的平均成绩。(保留小数点后两位)
                        第二行为有2门及2门以上不及格的学生的学号，各学号之间用一个空格分隔。若不存在，则打印"no"。
                        第三行为平均成绩在90分及以上的学生的学号, 各学号之间用一个空格分隔。若不存在，则打印"no"。
【样例输入】
3
070001 90 80 85 50 42
070002 93 95 90 88 92
070003 98 92 84 90 91
【样例输出】93.67
                        070001
                        070002 070003
【样例说明】本班有3个学生。
                        第1个学生学号为: 070001, 5门课程的成绩分别为: 90、80、85、50、42;
                        第2个学生学号为: 070002, 5门课程的成绩分别为: 93、95、90、88、92;
                        第3个学生学号为: 070003, 5门课程的成绩分别为: 98、92、84、90、91。
                       本班第1门课程的平均成绩为: 93.67; 有2门及2门以上不及格的学生的学号为: 070001;
                       平均成绩在90分及以上的学生的学号为: 070002、070003。
【评分标准】本题共2个测试点，每个测试点1.0分，共2.0分。
*/
#include<stdio.h>
#include<stdlib.h>
struct stu
{
	char x[20];
	int f[5];
	int sum;
}a[30],temp;
int cmp(const void*a,const void*b)
{
	return *(int *)a<*(int *)b?1:-1;
}
int main()
{
	int n,i,sum=0,f1[30],f2[30],p=0,q=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d%d%d",a[i].x,&a[i].f[0],&a[i].f[1],&a[i].f[2],&a[i].f[3],&a[i].f[4]);
		sum+=a[i].f[0];
		qsort(a[i].f,5,sizeof(int),cmp);
		a[i].sum=a[i].f[0]+a[i].f[1]+a[i].f[2]+a[i].f[3]+a[i].f[4];
		if(a[i].sum>=90*5) f1[p++]=i;
		if(a[i].f[3]<60&&a[i].f[4]<60) f2[q++]=i;

	}
	printf("%.2f\n",(float)sum/n);
	for(i=0;i<q;i++)
	{
		printf("%s ",a[f2[i]].x);
	}
	printf("\n");
	for(i=0;i<p;i++)
	{
		printf("%s ",a[f1[i]].x);
	}
	return 0;
}