/*
����������Ȧ��һ����������2��14���˽��ˣ��Ҿ����츣��ҡ�
��2���޺͵�14���޵ģ��ҽ���������ʶ�������������Է��������롭����
�ָ��������µ��޵����������������ҳ�����λҪ��͵ĵ�ù����
�����ʽ��

���밴�յ��޵��Ⱥ�˳�������֪�����ٸ����޵�������ÿ������ռһ�У�Ϊ������10��Ӣ����ĸ�ķǿյ��ʣ��Իس�������
һ��Ӣ�ľ�㡰.����־����Ľ�����������Ų����ڵ��������

�����ʽ��

���ݵ��������һ����������ۣ������ڵ�2����A�͵�14����B���������A and B are inviting you to dinner...����
��ֻ��Aû��B���������A is the only one for you...��������A��û�У��������Momo... No one is for you ...����

��������1��
GaoXZh
Magi
Einst
Quark
LaoLao
FatMouse
ZhaShen
fantacy
latesum
SenSen
QuanQuan
whatever
whenever
Potaty
hahaha
.
�������1��
Magi and Potaty are inviting you to dinner...
��������2��
LaoLao
FatMouse
whoever
.
�������2��
FatMouse is the only one for you...
��������3��
LaoLao
.
�������3��
Momo... No one is for you ...
*/
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	string s[100];
 	int t=1;
 	while(s[t-1]!=".")
 	{
 		cin>>s[t++];
 	}
 	t--;
 	if(t>14)
 	{
 		cout<<s[2]<<" and "<<s[14]<<" are inviting you to dinner..."<<endl;
 	}
 	else if(t>2)
 	{
 		cout<<s[2]<<" is the only one for you..."<<endl;
 	}
 	else 
 	{
 		cout<<"Momo... No one is for you ..."<<endl;
 	}
 	return 0;
 }
