#include <iostream>
#include <cstdio>
#include <string.h>
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn << 2] = { 0 };
int lazy[maxn << 2] = { 0 };
void pushDown(int rt, int m) {
	lazy[rt * 2] = lazy[rt];
	lazy[rt * 2 + 1] = lazy[rt];
	sum[rt * 2] = lazy[rt] * (m - m / 2);
	sum[rt * 2 + 1] = lazy[rt] * (m / 2);
	lazy[rt] = 0;
}
void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(lson);
	build(rson);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l&&r <= R) {
		return sum[rt];
	}
	if(lazy[rt]) pushDown(rt, r - l + 1);
	int m = (l + r) / 2;
	int ans = 0;
	if (L <= m)ans += query(L, R, lson);
	if (m < R)ans += query(L, R, rson);
	return ans;

}
void updata(int L, int R, int val, int l, int r, int rt) {
	if (L <= l&&r <= R) {
		lazy[rt] = val;
		sum[rt] = val*(r - l + 1);
		return;
	}
	if (lazy[rt]) pushDown(rt, r - l + 1); 
	int m = (l + r) / 2;
	if (L <= m)updata(L, R, val, lson);
	if (m < R)updata(L, R, val, rson);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
int main() {
//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)  {
		memset(lazy, 0, sizeof(lazy));//lazy[] 每次需要初始化，sum[]不需要，不过以后最好两个都初始化0
		int n,num;
		scanf("%d", &n);
		build(1, n, 1);
		scanf("%d", &num);
		while (num--) {
			int a, b, val;
			scanf("%d%d%d", &a, &b, &val);
			updata(a, b, val, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", i, query(1, n, 1, n, 1));
	}
	
	return 0;
}
/*
In the game of DotA, Pudge’s meat hook is actually the most horrible thing for most of the heroes. The hook is made up of several consecutive metallic sticks which are of the same length.




Now Pudge wants to do some operations on the hook.

Let us number the consecutive metallic sticks of the hook from 1 to N. For each operation, Pudge can change the consecutive metallic sticks, numbered from X to Y, into cupreous sticks, silver sticks or golden sticks.
The total value of the hook is calculated as the sum of values of N metallic sticks. More precisely, the value for each kind of stick is calculated as follows:

For each cupreous stick, the value is 1.
For each silver stick, the value is 2.
For each golden stick, the value is 3.

Pudge wants to know the total value of the hook after performing the operations.
You may consider the original hook is made up of cupreous sticks.
Input
The input consists of several test cases. The first line of the input is the number of the cases. There are no more than 10 cases.
For each case, the first line contains an integer N, 1<=N<=100,000, which is the number of the sticks of Pudge’s meat hook and the second line contains an integer Q, 0<=Q<=100,000, which is the number of the operations.
Next Q lines, each line contains three integers X, Y, 1<=X<=Y<=N, Z, 1<=Z<=3, which defines an operation: change the sticks numbered from X to Y into the metal kind Z, where Z=1 represents the cupreous kind, Z=2 represents the silver kind and Z=3 represents the golden kind.
Output
For each case, print a number in a line representing the total value of the hook after the operations. Use the format in the example.
Sample Input
1
10
2
1 5 2
5 9 3
Sample Output
Case 1: The total value of the hook is 24.
*/