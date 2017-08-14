#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
vector<pair <double, double> > v;
double dis(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
bool cmp(pair <double, double> &a, pair <double, double> &b) {
	return a.second < b.second;
}
double closeDis(int l, int r) {
	double d = 1e20;
	if (l == r) {
		return d;
	}
	if (l + 1 == r) {
		return dis(v[l], v[r]);
	}
	int mid = (l + r) / 2;
	double a = closeDis(l, mid);
	double b = closeDis(mid + 1, r);
	d = min(a, b);
	vector<pair <double, double> > vt;
	for (int i = l; i <= r; i++) {
		if (fabs(v[i].first - v[mid].first) <= d) {
			vt.push_back(v[i]);
		}
	}
	sort(vt.begin(), vt.end(),cmp);
	for (int i = 0; i < vt.size(); i++) {
		for (int j = i + 1; j < vt.size() && (vt[j].second - vt[i].second) < d; j++) {
			double temp = dis(vt[j], vt[i]);
			if (temp < d) {
				d = temp;
			}
		}
	}
	return d;
}
int main() {
	freopen("input.txt", "r", stdin);
	
	while (true) {
		int n;
		double x, y;
		scanf("%d", &n);
		if (n == 0)break;

		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			v.push_back(make_pair(x, y));
		}
		printf("%.2lf\n", closeDis(0, n - 1)/2);
		v.clear();
	}
	

	return 0;
}
