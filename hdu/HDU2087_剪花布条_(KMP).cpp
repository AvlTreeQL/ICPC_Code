/*
һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С����������һ���ܴӻ������о����ܼ�������С�������أ�
Input
�����к���һЩ���ݣ��ֱ��ǳɶԳ��ֵĻ�������С�������䲼�������ÿɼ�ASCII�ַ���ʾ�ģ��ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�������������С�������ᳬ��1000���ַ������������#�ַ������ٽ��й�����
Output
����ܴӻ��Ʋ��м��������С�������������һ�鶼û�У��Ǿ�����ʵʵ���0��ÿ�����֮��Ӧ���С�
Sample Input
abcde a3
aaaaaa  aa
#
Sample Output
0
3
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 1e3 + 10;
void getNext(string p, int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < p.length()) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int kmp(string S, string P, int next[]) {
	getNext(P, next);
	int i = 0, j = 0, cnt = 0;
	while (i < S.length()) {
		if (j == -1 || S[i] == P[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
		if (j == P.length()) {
			j = 0;
			cnt++;
		}
	}

	return cnt;
}
int main() {
//	freopen("input.txt", "r", stdin);
	while (true) {
		string a, b;
		cin >> a;
		if (a[0] == '#') break;
		cin >> b;
		int next[maxn];

		printf("%d\n", kmp(a, b, next));

	}
	return 0;
}