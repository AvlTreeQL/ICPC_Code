/*
There is a string A. The length of A is less than 1,000,000. I rewrite it again and again. Then I got a new string: AAAAAA...... Now I cut it from two different position and get a new string B. Then, give you the string B, can you tell me the length of the shortest possible string A. For example, A="abcdefg". I got abcd efgabcdefgabcdefgabcdefg.... Then I cut the red part: efgabcdefgabcde as string B. From B, you should find out the shortest A.
Input
Multiply Test Cases. For each line there is a string B which contains only lowercase and uppercase charactors. The length of B is no more than 1,000,000.
Output
For each line, output an integer, as described above.
Sample Input
bcabcab
efgabcdefgabcde
Sample Output
3
7
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 1e2 + 10;

void getNext(string p,int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < p.size()) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j=next[j];
	}
}
int main() {
//	freopen("input.txt", "r", stdin);
	string str;
	while (cin >> str) {
		int next[maxn] = { 0 };
		getNext(str, next);
		printf("%d\n", str.size() - next[str.size()]);//×î¶ÌÑ­»·½Ú
	}
	return 0;
}