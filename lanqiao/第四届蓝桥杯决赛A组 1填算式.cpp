/*
���⣺����ʽ

    �뿴�������ʽ��

    (ABCD - EFGH) * XY = 900

    ÿ����ĸ����һ��0~9�����֣���ͬ��ĸ����ͬ���֣���λ����Ϊ0��

    ���磬(5012 - 4987) * 36 ����һ���⡣

    ���ҵ���һ���⣬���ύ�ý��� ABCD �������������

    ���ϸ��ո�ʽ��ͨ��������ύ�𰸡�
    ע�⣺ֻ�ύ ABCD ���������������Ҫд�����������ݣ����磺˵���Ե����֡�
    
7153 6928 4
6048 5973 12
5012 4987 36

6048
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
#include<bits/stdc++.h>
using namespace std;
bool visit[10];
void check(int s[])
{
	int a=s[0]*1000+s[1]*100+s[2]*10+s[3];
	int b=s[4]*1000+s[5]*100+s[6]*10+s[7];
	int c=s[8]*10+s[9];
	if((a-b)*c==900)
	{
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
}
void dfs(int s[],int deep)
{
	if(deep==10)
	{
		check(s);
		return ;
	}
	for(int i=0;i<10;i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			s[deep]=i;
			dfs(s,deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	int s[10];
	dfs(s,0);
	return 0;
} 

