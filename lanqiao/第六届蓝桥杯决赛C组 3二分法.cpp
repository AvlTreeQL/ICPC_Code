/*
���⣺���ַ�

���ֲ��ҷ�ʮ�ֳ��ã�������������Ķ�����������
����ĳ��������������������������Ҳ����᷵��-1

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
		else ______________________________;  //���λ��
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

��������̣���д���߲���ȱʧ���롣

ע�⣺ֻ��дȱ�ٵĴ��룬��Ҫд�������д�����κ������������ݡ�


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
		else return k;  //���λ��
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
