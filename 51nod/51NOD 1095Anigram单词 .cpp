/*һ������a���ͨ��������������ĸ��˳����Եõ�����ĵ���b����ô����b��a��Anigram�����絥��army��mary��ΪAnigram�����ڸ���һ���ֵ䣬����Q�����ʣ��Ӹ������ֵ����ҳ���Щ���ʵ�Anigram��
Input
��1�У�1����N����ʾ�ֵ��е��ʵ�������(1 <= N <= 10000) 
��2 - N + 1�У��ֵ��еĵ��ʣ����ʳ��� <= 10�� 
��N + 2�У���ѯ������Q��(1 <= Q <= 10000) 
��N + 3 - N + Q - 2�У�������ѯ�ĵ��ʣ����ʳ��� <= 10��
Output
��Q�У����Anigram����������ͬ��2�����ʲ���Anigram�����û�����0��
Sample Input
5
add
dad
bad
cad
did
3
add
cac
dda
Sample Output
1
0
2
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<string,int> a;
	map<string,int> b;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		a[s]++;
		sort(s.begin(),s.end());
		b[s]++;
	} 
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int n1=a[s];
		sort(s.begin(),s.end());
		cout<<b[s]-n1<<endl;
	}
	return 0;
}


