/*
Given two sequences of numbers : a11, a22, ...... , aNN, and b11, b22, ...... , bMM (1 <= M <= 10000, 1 <= N <= 1000000). Your task is to find a number K which make aKK = b11, aK+1K+1 = b22, ...... , aK+M?1K+M?1 = bMM. If there are more than one K exist, output the smallest one. 
Input
The first line of input is a number T which indicate the number of cases. Each case contains three lines. The first line is two numbers N and M (1 <= M <= 10000, 1 <= N <= 1000000). The second line contains N integers which indicate a11, a22, ...... , aNN. The third line contains M integers which indicate b11, b22, ...... , bMM. All integers are in the range of ?1000000,1000000?1000000,1000000. 
Output
For each test case, you should output one line which only contain K described above. If no such K exists, output -1 instead. 
Sample Input
2
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 1 3
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 2 1
Sample Output
6
-1
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e4 + 10;
int N, M;
void getNext(int p[], int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < M) {
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
int kmp(int S[], int P[], int next[]) {
	getNext(P, next);
	int i = 0, j = 0;
	while (i < N && j < M) {
		if (j == -1 || S[i] == P[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == M) {
		return i - j + 1;
	}
	return -1;
}
int main() {
//	freopen("input.txt", "r", stdin);
	int C;
	scanf("%d", &C);
	while (C--) {
		int S[maxn] = { 0 };
		int P[maxm] = { 0 };
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &S[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &P[i]);
		}
		int next[maxm];

		printf("%d\n", kmp(S, P, next));

	}
	return 0;
}