/*
�ܶ�ѧУ����һ�ֱȽϵ�ϰ�ߡ���ʦ�Ǻ�ϲ��ѯ�ʣ���ĳĳ��ĳĳ���У�������ߵ��Ƕ��١�
���úܶ�ѧ���ܷ��С�

������ϲ��ϲ����������Ҫ�������ǣ����ǰ�����ʦ��Ҫ��дһ������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ���
Input
����Ŀ����������ԣ��봦���ļ�������
��ÿ�����Եĵ�һ�У������������� N �� M ( 0<N<=200000,0<M<5000 )���ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��ŷֱ��1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ���
��������M�С�ÿһ����һ���ַ� C (ֻȡ'Q'��'U') ��������������A��B��
��CΪ'Q'��ʱ�򣬱�ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B(����A,B)��ѧ�����У��ɼ���ߵ��Ƕ��١�
��CΪ'U'��ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��
Output
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ���
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