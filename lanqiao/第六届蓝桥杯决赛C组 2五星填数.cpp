/*

���⣺��������

�硾ͼ1.png��������ͼ���ڵ��������֣�1~12����ȥ7��11��
Ҫ��ÿ��ֱ�������ֺ���ȡ�

��ͼ����ǡ�������

�������ü�����������п��ܵ���ж����֡�
ע�⣺��ת�������ͬ����ͬһ�����

���ύ��ʾ������Ŀ����������Ҫ��д�κ��������ݡ�
	     0
	1  2  3  4
      5    6
        7
	8       9
*/
#include <bits/stdc++.h>
using namespace std; 
int a[10],num=0;
void check()
{
	int sum[15];
	sum[0]=a[1]+a[2]+a[3]+a[4];
	sum[1]=a[0]+a[2]+a[5]+a[8];
	sum[2]=a[0]+a[3]+a[6]+a[9];
	sum[3]=a[1]+a[5]+a[7]+a[9];
	sum[4]=a[4]+a[6]+a[7]+a[8];

	for(int i=1;i<5;i++)
	{
		if(sum[0]!=sum[i]) return ;
	}
	num++;

}
bool visit[10];

void dfs(int deep)  //����� ��֦ 
{
	if(deep==10)
	{
		check();
		return ;
	}
	for(int i=1;i<=12;i++)
	{
		if(!visit[i])
		{
			a[deep]=i;
			visit[i]=true;
			dfs(deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	visit[7]=visit[11]=true;
	dfs(0);
	cout<<num/10<<endl;
	return 0;
}
