#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			cout << a * 2 + b << endl;
		}
		else {
			cout << b * 2 + a << endl;
		}
	}
	return 0;
}