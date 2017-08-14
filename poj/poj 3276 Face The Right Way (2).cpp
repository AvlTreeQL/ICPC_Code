/*
Face The Right Way ��POJ No. 3276��
N ͷţ�ų���һ�С�ÿͷţ������ǰ�������Ϊ�������е�ţ������ǰ����ũ��Լ������
һ̨�Զ�ת��Ļ�������������ڹ���ʱ�ͱ����趨һ����ֵ K������ÿ����һ��ǡ��ʹ K
ͷ������ţת�������Ϊ�������е�ţ��������ǰ����Ҫ�����ٵĲ������� M �Ͷ�Ӧ��
��С�� K��
����
N = 7
BBFBFBB (F������ǰ����B�������)
���
K = 3
M = 3
���ȷ�ת1~3�ŵ���ͷţ��Ȼ���ٷ�ת3~5�ţ����ת5~7�ţ�
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX_N 20
using namespace std;
// ����
int N;
int dir[MAX_N]; // ţ�ķ���(0:F, 1:B)
int f[MAX_N]; // ����[i,i+K-1]�Ƿ���з�ת
// �̶�K�����Ӧ����С��������
// �޽�Ļ��򷵻�-1
int calc(int K) 
{
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0; // f�ĺ�
	for (int i = 0; i + K <= N; i++)
	{
	// ��������[i,i+K-1]
		if ((dir[i] + sum) % 2 != 0) 
		{
			// ǰ�˵�ţ�泯��
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - K + 1 >= 0) 
		{
			sum -= f[i - K + 1];
		}
	}
	// ���ʣ�µ�ţ�Ƿ����泯�󷽵����
	for (int i = N - K + 1; i < N; i++) 
	{
		if ((dir[i] + sum) % 2 != 0) 
		{
			// �޽�
			return -1;
		}
		if (i - K + 1 >= 0) 
		{
			sum -= f[i - K + 1];
		}
	}
	return res;
}
void solve() 
{
	int K = 1, M = N;
	for (int k = 1; k <= N; k++) 
	{
		int m = calc(k);
		if (m >= 0 && M > m) 
		{
			M = m;
			K = k;
		}
	}
	printf("%d %d\n", K, M);
}
int main()
{
	char c;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>c;
		dir[i]=c=='B'?1:0;
	}
	solve();
	return 0;
}
