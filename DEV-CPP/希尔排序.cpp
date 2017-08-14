#include<stdio.h>
void sort(int a[], int n);
int main()
{
	int a[30],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
void sort(int a[], int n) 
{  
    int i, j, gap,temp;  
    for (gap = n / 2; gap > 0; gap /= 2)  
        for (i = gap; i < n; i+=gap)  
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)  
			{
				temp=a[j];
				a[j]=a[j+gap];
				a[j+gap]=temp;
			}
}
