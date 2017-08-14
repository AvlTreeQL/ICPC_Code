#include <stdio.h>
void caculate(int m[] , int n , int x , int *num , float *aver);
int main()
{ int m[80],i=0,n,x,number;
 float av;
 while(1) {                     //循环读入数据
        scanf("%d",&m[i]);
        if(m[i]==-999) break;        //遇-999结束
        i++;
 }
 n=i;                           //输入数据的个数
 scanf("%d",&x);                 //输入正整数x
 caculate(m , n , x , &number , &av);
/* caculate函数功能是求给定数组平均值、统计比x小的个数。
 实际参数：m为数组名，n为数组中元素个数，av为平均值，
 number为比x小的正整数的个数。 */
 printf("%-10.2f%-5d\n",av,number);
 return(0);
}
void caculate(int m[] , int n , int x , int *num , float *aver)
{
	int s=0;
	int i;
	*num=0;
	for (i=0;i<n;i++)
		{
		s=s+m[i];
		}
	*aver=s/n;
	int a;
	for (a=0;a<n;a++);
		if(m[a]<x)
			*num=*num+1;
}

/*
【问题描述】

对于读入的N（N<80）个正整数，统计它们的平均值并统计其中比x小的数的个数。
程序主函数已给出并必须使用，主函数不能修改，完成函数部分。主函数实现了数据输入输出，由一个函数完成平均值的计算和个数统计，并将结果由函数参数返回。
程序主函数已给出并必须使用，主函数不能修改，完成函数部分。主函数实现了数据输入输出，第一行输入一组整数，输入-999表示输入数据结束，把输入的n个正整数放在m数组中，第二行输入整数x，请编写函数caculate，它的功能是：对m数组，求出这n个数的平均值（小数点保留两位）和统计比x小的数的个数。
#include <stdio.h>
void caculate(int m[] , int n , int x , int *num , float *aver);
int main()
{ int m[80],i=0,n,x,number;
 float av;
 while(1) {                     //循环读入数据
        scanf("%d",&m[i]);
        if(m[i]==-999) break;        //遇-999结束
        i++;
 }
 n=i;                           //输入数据的个数
 scanf("%d",&x);                 //输入正整数x
 caculate(m , n , x , &number , &av);
/* caculate函数功能是求给定数组平均值、统计比x小的个数。
 实际参数：m为数组名，n为数组中元素个数，av为平均值，
 number为比x小的正整数的个数。 */
 /*printf("%-10.2f%-5d\n",av,number);
 return(0);
}
void caculate(int m[] , int n , int x , int *num , float *aver)
{
    ……..//需要填写的代码
}
 【输入形式】
输入包括两行。第一行为一组正整数，当遇到 -999时表示本组数据结束，并且-999不处理；第二行为待与之比较的正整数x。
【输出形式】
输出占1行，为N个数的平均值以及比x小的正整数的个数。其中平均值列宽为10.2、人数列宽5，所有数据均左对齐。
参考输出格式：“%-10.2f%-5d\n”
【样例输入】
90 80 85 50 95 -999
86
【样例输出】
      80.00     3
【评分标准】
    本题有4个测试点，每个测试点5分，共20分。
	*/