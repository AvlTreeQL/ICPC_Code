/*

��ƽ����

��0~9��10�����֣��ֳɶ���飬ÿ����ǡ����һ��ƽ�����������ܹ��쵽�ġ�
���磺0, 36, 5948721

�ٱ��磺
1098524736
1, 25, 6390784
0, 4, 289, 15376
�ȵ�...

ע�⣬0������Ϊ���������֣���������Ϊ��λ���ֵĿ�ʼ��
����ʱ�������������е����֣������ظ���������©��

������ƽ�С�������ݵ��Ⱥ�˳�������ж����ֲ�ͬ�ķ��鷽����

ע�⣺��Ҫ�ύ����һ����������Ҫ��д�������ݡ�
answer:300

*/
#include <bits/stdc++.h>
using namespace std;
int a[]={0,1,2,3,4,5,6,7,8,9};
long long b[10];
long long c[10];
set<string> k;
void dfs(int deep,int num)
{
	if(deep==10)
	{
		memcpy(c,b,sizeof(b));
		sort(c,c+num);
		stringstream ss;
		string s,temp;
		for(int i=0;i<num;i++)
		{
			ss<<c[i];
			ss>>temp;
			s+='.';
			s+=temp;
			ss.clear();
		}
//		cout<<s<<endl;
//		system("pause");
		k.insert(s);
		return ;
	}
	if(a[deep]==0)
	{
		b[num]=0;
		dfs(deep+1,num+1);
	}
	else
	{
		long long sum=0;
		for(int i=deep;i<10;i++)
		{
			sum=sum*10+a[i];
			double son=sqrt(sum);
			if(son==(long long)son)
			{
				b[num]=sum;
				dfs(i+1,num+1);
		
			}
		}
	}
}
int main()
{
    do
    {
    	memset(b,0,sizeof(b));
    	dfs(0,0);
    }while(next_permutation(a,a+10));
    cout<<k.size()<<endl;
    return 0;
}

