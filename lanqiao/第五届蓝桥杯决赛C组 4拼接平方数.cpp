/*

���⣺ƴ��ƽ����

    С������49����Ȥ�����ȣ����Ǹ�ƽ�����������Բ��Ϊ4��9����ֳ����Ĳ���Ҳ��ƽ������169Ҳ��������ʣ�����Ȩ�ҳ�����Ϊ��ƴ��ƽ������

    100�ɲ��1 00�����е���ǿ�����ǹ涨��0 00 000 �ȶ�����ƽ������

    С���룺������Щ�������������أ�

    �����������ˣ��ҵ�ĳ�����������ƴ��ƽ������

�������ʽ��
����������  a b (a<b<10^6)

�������ʽ��
�����У�ÿ��һ������������ʾ���е�����[a,b]�е�ƴ��ƽ����

���磺
���룺
1 200

����Ӧ�������
49
169

�����磺
���룺
169 10000

����Ӧ�������
169
361
1225
1444
1681
3249
4225
4900
9025

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�

*/
#include <bits/stdc++.h>  
using namespace std;  
  
set<string>S;  
string a;
long long shu1[10];  
void check(long long i)  
{  
    string s1,s2;
    s1=a.substr(0,i);
    s2=a.substr(i,a.size()-i);
    long long aa,bb;
    stringstream ss;
    ss<<s1;
    ss>>aa;
    ss.clear();
    ss<<s2;
    ss>>bb;
  	double son1=sqrt(aa),son2=sqrt(bb);
  	if(!son1||!son2) return ;
  	if(son1==(long long)son1&&son2==(long long)son2)
  	{
  		cout<<a<<endl;
  	}
}  
  
int main()  
{  
	long long n,m;
	cin>>n>>m;
	for(long long i=n;i<=m;i++)
	{
		double son=sqrt(i);
		if(son!=(long long)son) continue;		
		stringstream ss;
		ss<<i;
		ss>>a;
		for(long long j=1;j<a.size();j++)
			check(j);
	}

    return 0;  
} 

