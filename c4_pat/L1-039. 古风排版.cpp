/*L1-039. �ŷ��Ű�
�й��Ĺ���д���֣��Ǵ������������Ű�ġ�����������д���򣬰�һ�����ְ��ŷ��Ű档
�����ʽ��
�����ڵ�һ�и���һ��������N��<100������ÿһ�е��ַ������ڶ��и���һ�����Ȳ�����1000�ķǿ��ַ������Իس�������
�����ʽ��
���ŷ��ʽ�Ű�������ַ�����ÿ��N���ַ����������һ�п��ܲ���N����
����������
4
This is a test case
���������
asa T
st ih
e tsi
 ce s
 */
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	int h,l,i,j,t=0;
 	string s;
	char s1[100][100];
 	cin>>h;
 	cin.get();
 	getline(cin,s);
 	l=s.size()/h;
	if(s.size()%h==0) 
	{
		l--;
	}
	else 
	{
		s.insert(s.size(),h-s.size()%h,' ');
	}
	
	for(i=l;i>=0;i--)
 	{
 		 for(j=0;j<h;j++)
 		 {
 			s1[j][i]=s[t++];
 //			cout<<s1[j][i]<<s[t-1]<<endl;
 		 }
 	}
 	for(i=0;i<h;i++)
 	{

 		cout<<s1[i]<<endl;
 	}
 	return 0;
 }
