/*
���⣺�Ȳ�������

2,3,5,7,11,13,....���������С�
���ƣ�7,37,67,97,127,157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
�ϱߵ����й���Ϊ30������Ϊ6��

2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
������������һ��˵ĳɹ���

����һ����Ϊ����������������еļ�������������ĵ�������

����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�

ע�⣺��Ҫ�ύ����һ����������Ҫ��д�κζ�������ݺ�˵�����֡�

*/
#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	if(x==2||x==3)
		return true;
	if(x%6!=1&&x%6!=5)
		return false;
	for(int i=5;i*i<=x;i+=6)
	{
		if(x%i==0||x%(i+2)==0)
			return false;
	} 
	return true;
}
int main()
{
	int i,j,k;
	for(i=3;1;i++)
	{
		for(j=2;j<100000;j++)
		{
			int flag=0;
			for(k=j;k<j+i*10;k+=i)
			{
				if(!check(k))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<i<<endl;
				for(int p=0;p<10;p++)
				{
					cout<<j+p*i<<' ';
				}
				system("pause");
			}
		}
	}
	return 0;
}
