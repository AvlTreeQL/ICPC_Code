/*


����һ����N����1��N�У��ж��ٸ�������2 3 5 7�ı����� ����N = 10��ֻ��1����2 3 5 7�ı�����



Input
����1����N(1 <= N <= 10^18)��

Output
�������2 3 5 7�ı����������ж��١�

Inputʾ��
10

Outputʾ��
1
*/
#include<bits/stdc++.h>
using namespace std;
bool visit[100000010];
int main()
{
	long long N;
	cin>>N;
	cout<<N-(N/2+N/3+N/5+N/7)+(N/2/3+N/2/5+N/2/7+N/3/5+N/3/7+N/5/7)-(N/2/3/5+N/2/3/7+N/3/5/7+N/2/5/7)+(N/2/3/5/7)<<endl;
	return 0;
}
