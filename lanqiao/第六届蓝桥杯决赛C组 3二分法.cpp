/*
标题：二分法

二分查找法十分常用，适用于在有序的队列中搜索。
下面的程序在有序整数数组中搜索，找不到会返回-1

#include <stdio.h>
#define N 23

int find(int* m, int k)
{
	int lo = 0;
	int hi = N-1;
	
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if      (k<m[mid]) hi = mid-1;
		else if (k>m[mid]) lo = mid+1;
		else ______________________________;  //填空位置
	}
	
	return -1;
}

int main()
{
	int m[N] = {1,4,5,8,11,13,14,15,22,27,35,46,48,49,49,51,60,62,62,62,71,74,88};
	printf("%d ", find(m,19));
	printf("%d ", find(m,49));
	printf("%d ", find(m,22));
	printf("\n");
	return 0;
}

请分析流程，填写划线部分缺失代码。

注意：只填写缺少的代码，不要写题面已有代码或任何其它多余内容。


*/
#include <stdio.h>
#define N 23

int find(int* m, int k)
{
	int lo = 0;
	int hi = N-1;
	
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(k<m[mid]) hi = mid-1;
		else if (k>m[mid]) lo = mid+1;
		else return k;  //填空位置
	}
	
	return -1;
}

int main()
{
	int m[N] = {1,4,5,8,11,13,14,15,22,27,35,46,48,49,49,51,60,62,62,62,71,74,88};
	printf("%d ", find(m,19));
	printf("%d ", find(m,49));
	printf("%d ", find(m,22));
	printf("\n");
	return 0;
}
