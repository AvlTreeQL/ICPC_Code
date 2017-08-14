/*
一个高度为N的由正整数组成的三角形，从上走到下，求经过的数字和的最大值。
每次只能走到下一层相邻的数上，例如从第3层的6向下走，只能走到第4层的2或9上。

   5
  8 4
 3 6 9
7 2 9 5

例子中的最优方案是：5 + 8 + 6 + 9 = 28
Input
第1行：N，N为数塔的高度。(2 <= N <= 500) 
第2 - N + 1行：每行包括1层数塔的数字，第2行1个数，第3行2个数......第k+1行k个数。数与数之间用空格分隔（0 <= Aii <= 10^5) 。
Output
输出最大值
Sample Input
4
5
8 4
3 6 9
7 2 9 5
Sample Output
28
*/
#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin>>a[i][j];
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=i;j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    cout<<a[0][0]<<endl;
    return 0;
}
