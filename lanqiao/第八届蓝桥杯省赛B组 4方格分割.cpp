/*
���⣺����ָ�

6x6�ķ������Ÿ��ӵı��߼����������֡�
Ҫ���������ֵ���״��ȫ��ͬ��

��ͼ��p1.png, p2.png, p3.png ���ǿ��еķָ��

�Լ��㣺
������3�ַַ����ڣ�һ���ж����ֲ�ͬ�ķָ����
ע�⣺��ת�ԳƵ�����ͬһ�ַָ��

���ύ����������Ҫ��д�κζ�������ݻ�˵�����֡�

*/
#include<bits/stdc++.h>
using namespace std;
bool visit[7][7];
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}},sum=0;
void dfs(int x,int y)
{
	if(visit[x][y])
		return ;
	visit[x][y]=true;
	visit[6-x][6-y]=true;
	if(x==0||y==0||x==6||y==6)//���� ����������Ե��ֹͣ���ڱ�Ե��ֽû������ 
	{
		sum++;
		visit[x][y]=false;
		visit[6-x][6-y]=false; //��������� ���� 
		return ;
	}
	
	for(int i=0;i<4;i++)
	{
		dfs(x+dir[i][0],y+dir[i][1]);
	}
	visit[x][y]=false;
	visit[6-x][6-y]=false;
}
int main()
{
	dfs(3,3);
	cout<<sum/4<<endl;
	return 0;
}
