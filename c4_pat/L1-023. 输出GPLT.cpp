#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	string s;
	cin>>s;
	a=count(&s[0],&s[s.size()],'G');
	a+=count(&s[0],&s[s.size()],'g');
	b=count(&s[0],&s[s.size()],'P');
	b+=count(&s[0],&s[s.size()],'p');
	c=count(&s[0],&s[s.size()],'L');
	c+=count(&s[0],&s[s.size()],'l');
	d=count(&s[0],&s[s.size()],'T');
	d+=count(&s[0],&s[s.size()],'t');
	while(!(a==0&&b==0&&c==0&&d==0))
	{
		if(a!=0) 
		{
			cout<<'G';
			a--;
		}
		if(b!=0) 
		{
			cout<<'P';
			b--;
		}
		if(c!=0) 
		{
			cout<<'L';
			c--;
		}
		if(d!=0) 
		{
			cout<<'T';
			d--;
		}
	}
	return 0;
}
/*
L1-023. ���GPLT
ʱ������
150 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���GPLTGPLT....��������˳������������������ַ�����Ȼ�������ַ��������ִ�Сд���ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�GPLT��˳���ӡ��ֱ�������ַ����������

�����ʽ��

������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��

��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
���������
GPLTGPLTGLTGLGLL
*/
