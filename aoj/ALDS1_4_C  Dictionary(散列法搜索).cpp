/*
Search III
Your task is to write a program of a simple dictionary which implements the following instructions:

insert str: insert a string str in to the dictionary
find str: if the distionary contains str, then print 'yes', otherwise print 'no'
Input
In the first line n, the number of instructions is given. In the following n lines, n instructions are given in the above mentioned format.

Output
Print yes or no for each find instruction in a line.

Constraints
A string consists of 'A', 'C', 'G', or 'T'
1 ≤ length of a string ≤ 12
n ≤ 1000000
Sample Input 1
5
insert A
insert T
insert C
find G
find A
Sample Output 1
no
yes
Sample Input 2
13
insert AAA
insert AAC
insert AGA
insert AGG
insert TTT
find AAA
find CCC
find CCC
insert CCC
find CCC
insert T
find TTT
find T
Sample Output 2
yes
no
no
yes
yes
yes
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 1e5;

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	map<string, int> mp;
	string a, b;
	while (n--) {
		cin >> a >> b;
		if (a[0] == 'i') {
			mp[b]++;
		}
		else {
			if (mp[b]) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
	return 0;
}