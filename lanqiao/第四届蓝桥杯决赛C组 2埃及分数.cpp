/*
���⣺��������

    �Ű���������������õ��������������ǵķ�����ʾȴ�����˲��⡣�Ű���ϲ����һ�������ֽ�Ϊ���ƣ� 1/a + 1/b �ĸ�ʽ��

    ���a �� b �����ǲ�ͬ���������������ӱ���Ϊ 1

    ���磬2/15 һ���� 4 �ֲ�ͬ�ķֽⷨ�����ҳ�Ϊ�����ֽⷨ����

1/8 + 1/120
1/9 + 1/45
1/10 + 1/30
1/12 + 1/20


    ��ô�� 2/45 һ���ж��ٸ���ͬ�İ����ֽ��أ�����ӷ������ɵ���ͬ�ַֽ⣩�� ��ֱ���ύ��������ǧ��Ҫ�ύ��ϸ�ķֽ�ʽ������

    ���ϸ���Ҫ��ͨ��������ύ�𰸡�
    ע�⣺ֻ�ύ�ֽ������������Ҫд�����������ݣ����磺˵���Ե�����
    answer:7
*/ 
#include<bits/stdc++.h>
using  namespace std;
long long sum=0,c=2,d=45;
void fun(int a,int b)
{
	long long fenzi=a+b;
	long long fenmu=a*b;
	for(long long i=2;i<=fenzi&&i<=fenmu;i++)
	{
		while(fenzi%i==0&&fenmu%i==0)
		{
			fenzi/=i;
			fenmu/=i;
		}
	}
//	cout<<fenzi<<'/'<<fenmu<<endl;
	if(fenzi==c&&fenmu==d)
	{
		cout<<1<<'/'<<a<<' '<<1<<'/'<<b<<endl;
		sum++;
	}
}
int main()
{
	
	for(int i=1000;i>0;i--)
	{
		for(int j=1000;j>0;j--)
		{
			if(i<=j)fun(i,j);
		}
	}
	cout<<sum<<endl;
	return 0;
}
