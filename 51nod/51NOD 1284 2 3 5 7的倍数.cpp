/*


给出一个数N，求1至N中，有多少个数不是2 3 5 7的倍数。 例如N = 10，只有1不是2 3 5 7的倍数。



Input
输入1个数N(1 <= N <= 10^18)。

Output
输出不是2 3 5 7的倍数的数共有多少。

Input示例
10

Output示例
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
