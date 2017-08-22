#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n, temp;
		cin >> n;
		vector<vector<int> > vec,vec2;
		vec.resize(n + 1);
		vec2.resize(n + 1);
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				cin >> temp;
				if (temp) {
					vec[i].push_back(i + j + 1);
				}
				else {
					vec2[i].push_back(i + j + 1);
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				int pos = vec[i][j];
				for (int k = 0; k < vec[pos].size(); k++) {
					if (binary_search(vec[i].begin(), vec[i].end(), vec[pos][k])) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
			for (int j = 0; j < vec2[i].size(); j++) {
				int pos = vec2[i][j];
				for (int k = 0; k < vec2[pos].size(); k++) {
					if (binary_search(vec2[i].begin(), vec2[i].end(), vec2[pos][k])) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if(!flag) cout << "Great Team!" << endl;
		else cout << "Bad Team!" << endl;
	}
	return 0;
}