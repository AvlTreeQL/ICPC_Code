/*
L2-022. ��������

����һ�������� L1��L2��...��Ln-1��Ln�����д����������������Ϊ Ln��L1��Ln-1��L2��...�����磺����LΪ1��2��3��4��5��6�������Ӧ��Ϊ6��1��5��2��4��3��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ�ͽ���ܸ�������������N (<= 105)�����ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣������ݣ�Ϊ������105����������Next����һ���ĵ�ַ����Ŀ��֤������������������������㡣

�����ʽ��

��ÿ������������˳��������ź�Ľ����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1

00 3
00 1 01
01 2 02
02 3 -1
03 3 00
00 1
 0 01
01 2
 0 02
02 0 -1
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int> key;
	map<string,string> next;
	map<string,string> last;
	string s,h,t;
	int n;
	cin>>s>>n;
	int pp=n;
	while(n--)
	{
		string h,t;
		int k;
		cin>>h>>k>>t;
		key[h]=k;
		next[h]=t;
		last[t]=h;
	}
	h=s;
	t="-1";
	cout<<last[t]<<' '<<key[last[t]]<<' ';
	t=last[t];
	for(int i=0;i<pp/2;h=next[h],t=last[t],i++)
	{
		cout<<h<<endl<<h<<' '<<key[h]<<' ';
		if(next[h]==t) break;
		cout<<last[t]<<endl<<last[t]<<' '<<key[last[t]]<<' ';
	}
	cout<<"-1";
	return 0;
}
