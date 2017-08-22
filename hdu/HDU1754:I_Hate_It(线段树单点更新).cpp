/*
很多学校流行一种比较的习惯。老师们很喜欢询问，从某某到某某当中，分数最高的是多少。
这让很多学生很反感。

不管你喜不喜欢，现在需要你做的是，就是按照老师的要求，写一个程序，模拟老师的询问。当然，老师有时候需要更新某位同学的成绩。
Input
本题目包含多组测试，请处理到文件结束。
在每个测试的第一行，有两个正整数 N 和 M ( 0<N<=200000,0<M<5000 )，分别代表学生的数目和操作的数目。
学生ID编号分别从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩。
接下来有M行。每一行有一个字符 C (只取'Q'或'U') ，和两个正整数A，B。
当C为'Q'的时候，表示这是一条询问操作，它询问ID从A到B(包括A,B)的学生当中，成绩最高的是多少。
当C为'U'的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
Output
对于每一次询问操作，在一行里面输出最高成绩。
Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
Sample Output
5
6
5
9
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
using namespace std;
const int maxn = 200010;
int sum[4 * maxn] ;
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &sum[rt]);
		return;
	}
	int m = (l + r) / 2;
	build(lson);
	build(rson);
	sum[rt] = max(sum[rt * 2], sum[rt * 2 + 1]);
}
int query(int s, int e, int l, int r, int rt) {
	if (s <= l&&r <= e) {
		return sum[rt];
	}
	int m = (l + r) / 2;
	int ret = -1;
	if (s <= m)  ret=max(ret, query(s, e, lson));
	if (m < e)  ret=max(ret, query(s, e, rson));
	return ret;
}
void add(int i, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = val;
		return;
	}
	int m = (l + r) / 2;
	if (i <= m) add(i, val, lson);
	else add(i, val, rson);
	sum[rt] = max(sum[rt * 2], sum[rt * 2 + 1]);
}
int main() {
//	freopen("input.txt", "r", stdin);
	int n,num;
	while(~scanf("%d%d", &n, &num)) {
	//	memset(sum, 0, sizeof(sum));
		build(1, n, 1);
		char c;
		int a, b;
		while (num--) {
			getchar();
			scanf("%c%d%d", &c,&a, &b);
			if (c == 'Q') {
				printf("%d\n", query(a, b, 1, n, 1));
			}
			else {
				add(a, b, 1, n, 1);
			}
		}
	}
	

	return 0;
}