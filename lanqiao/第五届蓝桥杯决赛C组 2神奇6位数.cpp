/*

���⣺����6λ��

  ��һ��6λ�������������и�����������ʣ�

  �ֱ���2 3 4 5 6ȥ�������õ�����Ȼ��6λ�������ҳ˻��������������������6λ����ȫһ����ֻ���������ǵ�˳�����������˶��ѡ�

  ���������6λ����

  ����һ����������ͨ��������ύ�𰸣���Ҫ��д�κζ�������ݣ�����˵���Ե����֣�
  answer: 142857
  */
#include<bits/stdc++.h>
using namespace std;
string check(int x)
{
	string s;
	stringstream ss;
	ss<<x;
	ss>>s;
	sort(s.begin(),s.end());
	return s;
}
int main()
{
	for(int i=100000;i<1000000;i++)
	{
		string t=check(i);
		if(2*i>=1000000||t!=check(2*i))
			continue;
		if(3*i>=1000000||t!=check(3*i))
			continue;
		if(4*i>=1000000||t!=check(4*i))
			continue;
		if(5*i>=1000000||t!=check(5*i))
			continue;
		if(6*i>=1000000||t!=check(6*i))
			continue;
		cout<<i<<endl;
		system("pause"); 
	}
	return 0;
}
