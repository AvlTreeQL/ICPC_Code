#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};
	string n;
	cin>>n;
	if(n[0]=='-') n[0]='0'+10;
	for(int i=0;i<n.size();i++)
	{
		if(i!=n.size()-1) cout<<s[n[i]-'0']<<' ';
		else cout<<s[n[i]-'0'];
	}

	return 0;
} 
/*
L1-007. ������
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
����
����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ���������fu���֡�ʮ�����ֶ�Ӧ��ƴ�����£�

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
�����ʽ��

������һ���и���һ���������磺 1234 ��

��ʾ�������������������������

�����ʽ��

��һ����������������Ӧ��ƴ����ÿ�����ֵ�ƴ��֮���ÿո�ֿ�����ĩû�����Ŀո��� yi er san si��

����������
-600
���������
fu liu ling ling

*/
