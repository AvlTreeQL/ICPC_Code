/*

���⣺�����˻�

Ϊ���󷴸����ȣ�ĳ�ؾ���ר��֧�ӣ������������˻�չ�����顣

��������˻��䷢����ת�ˣ�����Ϊ�й��������a,b���й���, b,c���й���������Ϊa,c��Ҳ�й�����

���ڵ��鷶Χ�ڵ�n���˻������0��n-1����������֪��m����ת�������ֱ�ӹ�����

����ϣ��֪����������������˻���������Ǽ��Ƿ��й������й��������1��û�й������0

С�����������µĽ��������

#include <stdio.h>
#define N 100

int connected(int* m, int p, int q)
{
	return m[p]==m[q]? 1 : 0;
}

void link(int* m, int p, int q)
{
	int i;
	if(connected(m,p,q)) return;
	int pID = m[p];
	int qID = m[q];
	for(i=0; i<N; i++) _____________________________________;  //���λ��
}

int main()
{
	int m[N];
	int i;
	for(i=0; i<N; i++) m[i] = i; //��ʼ״̬��ÿ���ڵ��Գ�һ����ͨ��
	link(m,0,1); //��������˻����ת�˹���
	link(m,1,2); 
	link(m,3,4); 
	link(m,5,6); 
	link(m,6,7); 
	link(m,8,9); 
	link(m,3,7); 
	
	printf("%d ", connected(m,4,7));
	printf("%d ", connected(m,4,5));
	printf("%d ", connected(m,7,9));
	printf("%d ", connected(m,9,2));
	return 0;
}

�����Դ���룬���ύ���߲���ȱ�ٵĴ��롣��Ҫ��д���д�����κζ������ݡ�
answer: if(m[i]==pID)m[i]=qID;
	*/
#include <stdio.h>
#define N 100

int connected(int* m, int p, int q)
{
	return m[p]==m[q]? 1 : 0;
}

void link(int* m, int p, int q)
{
	int i;
	if(connected(m,p,q)) return;
	int pID = m[p];
	int qID = m[q];
	for(i=0; i<N; i++) 
		if(m[i]==pID)m[i]=qID; //���λ��
//		if(m[i]==m[p]) m[i]=m[q]; ���� ��Ϊ m[i]�ĸı� ���ܻ�ı� m[p] m[q] 
}

int main()
{
	int m[N];
	int i;
	for(i=0; i<N; i++) m[i] = i; //��ʼ״̬��ÿ���ڵ��Գ�һ����ͨ��
	link(m,0,1); //��������˻����ת�˹���
	link(m,1,2); 
	link(m,3,4); 
	link(m,5,6); 
	link(m,6,7); 
	link(m,8,9); 
	link(m,3,7); 

	printf("%d ", connected(m,6,5));
	printf("%d ", connected(m,4,5));
	printf("%d ", connected(m,3,6));
	printf("%d ", connected(m,9,8));
	return 0;
}
