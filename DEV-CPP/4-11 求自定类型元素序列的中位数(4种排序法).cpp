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
//ϣ������
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
ð������	n2	n2
��������	n2	n2
��������	n2	n2
ѡ������	n2	n2
������	nlogn	nlogn
***�鲢����	nlogn	nlogn
��������	n2	nlogn

 //ֱ�Ӳ�������
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

//ð�ݷ�
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

//ѡ��
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
4-11 ���Զ�����Ԫ�����е���λ��   (25��)
����Ҫ��ʵ��һ����������N������Ԫ��A[]����λ�����������е�\lfloor N/2 +1\rfloor?N/2+1?���Ԫ�ء����м���Ԫ�ص�����Ϊ�Զ����ElementType��
�����ӿڶ��壺

ElementType Median( ElementType A[], int N );
���и�������Ԫ�ش��������A[]�У�������N������Ԫ�ظ������ú����뷵��N��A[]Ԫ�ص���λ������ֵҲ������ElementType���͡�
���в��Գ���������

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
��Ĵ��뽫��Ƕ������ 
����������

3
12.3 34 -5
���������

12.30
*/