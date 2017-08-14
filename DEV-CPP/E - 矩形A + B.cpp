#include<stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        __int64 sum=0;
        sum+=n*(n+1)/2*m*(m+1)/2;
        printf("%I64d\n",sum);
    }
    return 0;
}
/*
给你一个高为n ，宽为m列的网格，计算出这个网格中有多少个矩形，下图为高为2，宽为4的网格. 
____________
|	  | 	|
|	  |     |
|_____|_____|
|	  |     |
|_____|_____|
Input
第一行输入一个t, 表示有t组数据，然后每行输入n,m,分别表示网格的高和宽 ( n < 100 , m < 100). 
Output
每行输出网格中有多少个矩形.
Sample Input
2
1 2
2 4
Sample Output
3
30
*/