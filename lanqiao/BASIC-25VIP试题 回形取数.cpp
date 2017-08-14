/*问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2
*/
#include<stdio.h>  
int main()  
{      
	int m,n,i,j,t=0,a[201][201],flag=0;      
	scanf("%d%d",&m,&n);      
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	while(1)
	{
		
		if(t!=m-t)
			for(i=t,j=t;i<m-t;i++)
				flag=1,printf("%d ",a[i][j]);
		else break;
		if(flag==1)
			for(i--,j++;j<n-t;j++)
				flag=0,printf("%d ",a[i][j]);
		else break;
		if(flag==0)
			for(i--,j--;i>=t;i--)
				flag=1,printf("%d ",a[i][j]);
		else break;
		if(flag==1)
			for(i++,j--;j>=t+1;j--)
				flag=0,printf("%d ",a[i][j]);
		else break;
		t++;
		
	}
	return 0;
} 
