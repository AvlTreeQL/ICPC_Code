#include <stdio.h>
int main()
{ 
	int a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
	int i,j,row=0,colum=0,max;
		max=a[0][0];
	for(i=0;i<=2;i++)
		for(j=0;j<=3;j++)
			if(a[i][j]>max)
			{ 
				max=a[i][j];
				row=i;
				colum=j;
			}
	printf("max=%d,row=%d, colum=%d\n",max,row,colum);
	return 0;
} 