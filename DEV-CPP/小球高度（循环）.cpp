#include<stdio.h>
int main()
{
	int n,a=2;
	float i=100.00,t,b=100.00;
	scanf("%d",&n);
	while(a<=n&&a>1)
	{
		i=i+b;
		b=b/2;
		a=a+1;
	}
	t=b/2;
	printf("%.2f %.2f\n",i,t);
	return 0;
}
/*问题描述
一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，请编写一个程序求它在第n次落地时，共经过多少米？第n次反弹多高？
输入形式
输入一行，包括一个整数n，表示第n次落地。
输出形式
输出一行，输出第n次落地时共经过的总米数和第n次反弹的高度，两数之间以空格分隔。小数点保留两位。
样例输入
2
样例输出
      200.00 25.00  */