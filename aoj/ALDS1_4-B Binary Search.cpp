/*
Search II
You are given a sequence of n integers S and a sequence of different q integers T. Write a program which outputs C, the number of integers in T which are also in the set S.

Input
In the first line n is given. In the second line, n integers are given. In the third line q is given. Then, in the fourth line, q integers are given.

Output
Print C in a line.

Constraints
Elements in S is sorted in ascending order
n ≤ 100000
q ≤ 50000
0 ≤ an element in S ≤ 109
0 ≤ an element in T ≤ 109
Sample Input 1
5
1 2 3 4 5
3
3 4 1
Sample Output 1
3
Sample Input 2
3
1 2 3
1
5
Sample Output 2
0
Sample Input 3
5
1 1 2 2 3
2
1 2
Sample Output 3
2
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 1e5;

int search(int a[], int n, int val) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (a[m] >= val) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return a[r + 1] == val ? r + 1 : -1;
}
int main() {
//	freopen("input.txt", "r", stdin);
	int n;
	int a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int q;
	scanf("%d", &q);
	int sum = 0;
	for(int i=0;i<q;i++){
		int x;
		scanf("%d", &x);
		if (search(a,n,x)!=-1) sum++;
	}
	printf("%d\n", sum);
	return 0;
}