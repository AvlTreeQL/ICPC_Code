/*

标题：四阶幻方

把1~16的数字填入4x4的方格中，使得行、列以及两个对角线的和都相等，满足这样的特征时称为：四阶幻方。

四阶幻方可能有很多方案。如果固定左上角为1，请计算一共有多少种方案。
比如：
  1  2 15 16
 12 14  3  5
 13  7 10  4
  8 11  6  9

以及：
  1 12 13  8
  2 14  7 11
 15  3 10  6
 16  5  4  9
 
就可以算为两种不同的方案。

请提交左上角固定为1时的所有方案数字，不要填写任何多余内容或说明文字。

0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15

*/
#include<bits/stdc++.h>
using namespace std;
int a[4][4]={1},num=0;
bool visit[16];
void dfs(int a[],int deep)
{
	if(deep>4&&(a[0]+a[1]+a[2]+a[3])!=34) return ;// 和一定为34 剪枝 要用到！！！！ 
	if(deep>7&&(a[0]+a[1]+a[2]+a[3])!=(a[4]+a[5]+a[6]+a[7]))
		return ;
	if(deep>11&&(a[0]+a[1]+a[2]+a[3])!=(a[8]+a[9]+a[10]+a[11]))
		return ;
	if(deep>15)
	{

		if(a[0]+a[1]+a[2]+a[3]!=a[12]+a[13]+a[14]+a[15])
			return ;
		if(a[0]+a[4]+a[8]+a[12]!=a[0]+a[1]+a[2]+a[3])
			return ;	
		if(a[0]+a[4]+a[8]+a[12]!=a[1]+a[5]+a[9]+a[13])
			return ;
		if(a[0]+a[4]+a[8]+a[12]!=a[2]+a[6]+a[10]+a[14])
			return ;
		if(a[0]+a[4]+a[8]+a[12]!=a[3]+a[7]+a[11]+a[15])
			return ;
		if(a[0]+a[4]+a[8]+a[12]!=a[3]+a[6]+a[9]+a[12])
			return ;
		if(a[0]+a[5]+a[10]+a[15]!=a[3]+a[6]+a[9]+a[12])
			return ;
	}
	if(deep==16)
	{
		num++;
		return ;
	}
	for(int i=2;i<=16;i++)
	{
		if(!visit[i])
		{
			a[deep]=i;
			visit[i]=true;
			dfs(a,deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	dfs(*a,1);
	cout<<num<<endl;
	return 0;
} 
