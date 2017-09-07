#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	cin.get();
	while (t--) {
		int a[30] = { 0 };
		char c;
		while (true) {
			c = cin.get();
			if (c == '\n') break;
			a[c - 'A']++;
		}
		cout << a['H' - 'A'] + a['C' - 'A'] * 12 + a['O' - 'A'] * 16 << endl;
	}
	
	return 0;
}