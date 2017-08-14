/*
问题描述
　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。
输入格式
　　输入仅包含两行，每行描述一个矩形。
　　在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。
输出格式
　　输出仅包含一个实数，为交的面积，保留到小数后两位。
样例输入
1 1 3 3
2 2 4 4
样例输出
1.00
*/
#include<stdio.h>
void swap(double *a,double *b)
{
	double t;
	t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,s;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	if(x1>x2) swap(&x1,&x2);
	if(y1>y2) swap(&y1,&y2);
	if(x3>x4) swap(&x3,&x4);
	if(y3>y4) swap(&y3,&y4);
	if(x1>x3) x5=x1;
	else x5=x3;
	if(y1>y3) y5=y1;
	else y5=y3;
	if(x2>x4) x6=x4;
	else x6=x2;
	if(y2>y4) y6=y4;
	else y6=y2;
	if(x6-x5<0||y6-y5<0) printf("0.00");
	else printf("%.2lf",(x6-x5)*(y6-y5));
	return 0;
}

