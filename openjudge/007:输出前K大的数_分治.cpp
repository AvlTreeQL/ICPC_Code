/*************************************************************************
	> File Name: 007:输出前K大的数_分治.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月23日 星期三 15时41分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool cmp(int &a, int &b)
{
    return a > b;
}
void quicksort(int a[], int s, int e)
{
    int i = s, j = e;
    int k = a[s];
    if(s >= e) return ;
    while(i != j) {
        while(i < j && a[j] <= k) {
            j--;
        }
        swap(a[i], a[j]);
        while(i < j && a[i] >= k) {
            i++;
        }
        swap(a[i], a[j]);
    }
    if(i+1 == m) {
        return ;
    }
    if(i+1 > m) quicksort(a, s, i - 1);
    else quicksort(a, i + 1, e);
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    quicksort(a, 0, n - 1);
    sort(a,a+m,cmp);
    for(int i = 0; i < m; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
