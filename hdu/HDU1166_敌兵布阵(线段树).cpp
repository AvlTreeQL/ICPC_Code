/*
C��������ͷA�����ʱ�����ڽ��о�����ϰ������C�����ͷ��Derek��������Tidy�ֿ�ʼæ���ˡ�A���ں�������ֱ�߲�����N������Ӫ��,Derek��Tidy���������Ҫ������Щ����Ӫ�صĻ��������ڲ�ȡ��ĳ���Ƚ��ļ���ֶΣ�����ÿ������Ӫ�ص�����C�������յ�һ�����,ÿ������Ӫ�ص��������п��ܷ����䶯���������ӻ������������,����Щ���Ӳ���C���ļ��ӡ�
�����鱨��Ҫ�о����˾�����ϰʲôս��,����TidyҪ��ʱ��Derek�㱨ĳһ�������Ĺ���Ӫ��һ���ж�����,����Derek��:��Tidy,���ϻ㱨��3��Ӫ�ص���10��Ӫ�ع��ж�����!��Tidy��Ҫ���Ͽ�ʼ������һ�ε����������㱨�����б�Ӫ�ص����������䶯����Derekÿ��ѯ�ʵĶζ���һ��������Tidy���ò�ÿ�ζ�һ��һ��Ӫ�ص�ȥ�����ܿ�;�ƣ�����ˣ�Derek��Tidy�ļ����ٶ�Խ��Խ����:"��������У������ô�����ҳ�������!��Tidy�룺�����Լ������㿴���������һ�����˵Ĺ���!�Һ޲����㳴��������!������֮�£�Tidyֻ�ô�绰������ר��Windbreaker���,Windbreaker˵���������У�����ƽʱ�����acm��Ϳ�����㷨�飬���ڳ�������˰�!��Tidy˵��"��֪���ˡ�����"��Windbreaker�Ѿ��ҵ��绰�ˡ�Tidy�ܿ��գ���ô������Ļ�����ģ������Ķ��ߣ�����д������������������𣿲��������ĳ���Ч�ʲ����ߵĻ���Tidy���ǻ��ܵ�Derek�������.
Input
��һ��һ������T����ʾ��T�����ݡ�
ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ���������N��������,��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50����
������ÿ����һ�����������4����ʽ��
(1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30��
(2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��;
(3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������;
(4)End ��ʾ����������������ÿ������������;
ÿ�����������40000������
Output
�Ե�i������,���������Case i:���ͻس�,
����ÿ��Queryѯ�ʣ����һ���������س�,��ʾѯ�ʵĶ��е�������,�����������int���ڡ�
Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End
Sample Output
Case 1:
6
33
59
*/
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 1e5;
int sum[4 * maxn] ;
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &sum[rt]);
		return;
	}
	int m = (l + r) / 2;
	build(l, m, rt * 2);
	build(m + 1, r, rt * 2 + 1);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
int query(int s, int e, int l, int r, int rt) {
	if (s <= l&&r <= e) {
		return sum[rt];
	}
	int m = (l + r) / 2;
	int sum1 = 0;
	if (s <= m) {
		sum1 +=query(s, e, l, m, rt * 2);
	}
	if (m < e) {//m<e ����m<=e  �߼��� Ҳ�� m+1<=e �����洫��Ĳ���
		sum1 += query(s, e, m + 1, r, rt * 2 + 1);
	}
	return sum1;
}
void add(int i, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] += val;
		return;
	}
	int m = (l + r) / 2;
	if(i<=m) add(i, val, l, m, rt * 2);//i<=m ����i<m
	else add(i, val, m + 1, r, rt * 2 + 1);
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}
int main() {
//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++){
		printf("Case %d:\n", i);
		int n;
		scanf("%d", &n);
		build(1, n, 1);
		char str[10];
		while (scanf("%s",str)) {
			if (str[0] == 'E') break;

			int a, b;
			scanf("%d%d", &a, &b);

			if (str[0] == 'Q') {
				printf("%d\n",query(a, b, 1, n, 1));
			}
			else if (str[0] == 'A') {
				add(a, b, 1, n, 1);
			}
			else {
				add(a, -b, 1, n, 1);
			}
		}
	}
	return 0;
}