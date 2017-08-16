/*************************************************************************
	> File Name: 3617:Best_Cow_Line_贪心.cpp
	> Author: heheql
	> Mail: 374655767@qq.com
	> Created Time: 2017年08月16日 星期三 15时52分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
char a[2010];
bool check(int l, int r)
{
    for(int i = l, j = r; i < j; i++, j--) {
        if(a[i] == a[j]) continue;
        if(a[i] < a[j]) return true;
        else return false;
    }
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1, num = 0;
    while(l <= r) {
        if(a[l] < a[r]) {
            cout << a[l++];
        } else if(a[l] > a[r]) {
            cout << a[r--];
        } else {
            if(check(l, r)) {
                cout << a[l++];
            } else {
                cout << a[r--];
            }
        }
        num++;
        if(num % 80 == 0) cout << endl;
    }

    return 0;
}
