/*Problem Description
You are encountered with a traditional problem concerning the sums of powers.
Given two integers n and k . Let f(i)=ik , please evaluate the sum f(1)+f(2)+...+f(n) . The problem is simple as it looks, apart from the value of n in this question is quite large.
Can you figure the answer out? Since the answer may be too large, please output the answer modulo 109+7 .
 
 

Input
The first line of the input contains an integer T(1≤T≤20) , denoting the number of test cases.
Each of the following T lines contains two integers n(1≤n≤10000) and k(0≤k≤5) .
 
 

Output
For each test case, print a single line containing an integer modulo 109+7 .
 
 

Sample Input
3 2 5 4 2 4 1
 
 

Sample Output
33 30 10
*/
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
ll quick(ll a, ll b) {// 这里 a,b 要为 long long ,因为 a会变得很大
	ll ret = 1;
	while (b) {
		if (b & 1) {//相当于 b%2
			ret = (ret*a) % mod;
		}
		a = (a*a) % mod;
		b >>= 1;
	}
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		ll sum = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			sum = (sum + quick(i, k)) % mod;
		printf("%lld\n", sum);
	}
	return 0;
}