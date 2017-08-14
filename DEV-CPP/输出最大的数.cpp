#include<stdio.h>
int main()
{
	int max,a;
	scanf("%d",&a);
	max=a;
	for(int i=2;i<=3;i++)
	{
		scanf("%d",&a);
		if(a>max) max=a;
	}
	printf("%d\n",max);
	return 0;
}
/* 【问题描述】有3个整数a、b、c，由键盘输人，输出其中最大的数。

【输入形式】输入一行，包括3个整数。

【输出形式】输出一行，输出三个数中较大的数。

【样例输入】1 2 10

【样例输出】10

【评分标准】本题共有4个测试点，满分1.0分。 */