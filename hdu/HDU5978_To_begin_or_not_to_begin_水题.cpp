#include <iostream>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int k;
	while (cin >> k) {
		if (k & 1) {// k+1为偶数
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	return 0;
}