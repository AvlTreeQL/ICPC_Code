#include <iostream>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	int m = 255; // pow(2,8)-1
	while (cin >> n) {
		int a, ans = 0;
		while (n--) {
			cin >> a;
			for (int i = 0; i < 4; i++) {
				int temp = a >> (i * 8);
				temp &= m;
				if (temp == 97) ans++;
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}