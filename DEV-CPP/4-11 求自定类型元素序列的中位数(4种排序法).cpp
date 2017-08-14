#include <stdio.h>
#define MAXN 10
typedef float ElementType;
ElementType Median( ElementType A[], int N );
int main ()
{
    ElementType A[MAXN];
    int N, i;
    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    return 0;
}
//希尔排序
ElementType Median( ElementType A[], int N )
{
    int i,j,gap;
    for (gap=N/2;gap; gap/=2)
        for (i=gap; i<N; i++)
            for (j=i-gap;j>=0&&A[j]>A[j+gap];j-=gap)
            {
                ElementType temp=A[j];
                A[j]=A[j+gap];
                A[j+gap]=temp;
            }
    return A[N/2];
}
/*
冒泡排序	n2	n2
计数排序	n2	n2
插入排序	n2	n2
选择排序	n2	n2
堆排序	nlogn	nlogn
***归并排序	nlogn	nlogn
快速排序	n2	nlogn

 //直接插入排序
ElementType Median( ElementType A[], int N )
{  
    int i, j; 
	ElementType B;
    for (i=1;i<N;i++)  
        for (j=i-1;j>=0&&A[j]>A[j+1];j--)  
		{
			B=A[j];
			A[j]=A[j+1];
			A[j+1]=B;
		}  
	return A[N/2];
}

//冒泡法
ElementType Median( ElementType A[], int N )
{
	int i,j;
	ElementType B;
	for(i=0;i<N-1;i++)
		for(j=0;j<N-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				B=A[j];
				A[j]=A[j+1];
				A[j+1]=B;
			}
		}
	return A[N/2];
}

//选择法
ElementType Median( ElementType A[], int N )
{
	int i,j,min;
	ElementType tmp;
	for(i=0;i<N-1;i++)  
    {  
        min=i;  
        for(j=i+1;j<N;j++)  
        {  
            if (A[min]>A[j]) min=j;  
        }  
        if(i!=min)  
        {  
            tmp=A[i];  
            A[i]=A[min];  
            A[min]=tmp;  
        }  
    }
	return A[N/2];
}
4-11 求自定类型元素序列的中位数   (25分)
本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第\lfloor N/2 +1\rfloor?N/2+1?大的元素。其中集合元素的类型为自定义的ElementType。
函数接口定义：

ElementType Median( ElementType A[], int N );
其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。
裁判测试程序样例：

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}
你的代码将被嵌在这里 
输入样例：

3
12.3 34 -5
输出样例：

12.30
*/