/*L3-015. 球队“食物链”

某国的足球联赛中有N支参赛球队，编号从1至N。
联赛采用主客场双循环赛制，参赛球队两两之间在双方主场各赛一场。
联赛战罢，结果已经尘埃落定。
此时，联赛主席突发奇想，希望从中找出一条包含所有球队的“食物链”，来说明联赛的精彩程度。
“食物链”为一个1至N的排列{ T1 T2 ... TN }，满足：球队T1战胜过球队T2，球队T2战胜过球队T3，……，球队T(N-1)战胜过球队TN，球队TN战胜过球队T1。
现在主席请你从联赛结果中找出“食物链”。若存在多条“食物链”，请找出字典序最小的。

注：排列{ a1 a2 ...aN }在字典序上小于排列{ b1 b2 ... bN }，当且仅当存在整数K（1 <= K <= N），满足：aK < bK且对于任意小于K的正整数i，ai=bi。

输入格式：

输入第一行给出一个整数N（2 <= N <= 20），为参赛球队数。
随后N行，每行N个字符，给出了NxN的联赛结果表，
其中第i行第j列的字符为球队i在主场对阵球队j的比赛结果：
“W”表示球队i战胜球队j，“L”表示球队i负于球队j，“D”表示两队打平，“-”表示无效（当i=j时）。输入中无多余空格。

输出格式：

按题目要求找到“食物链”T1 T2 ... TN，将这N个数依次输出在一行上，数字间以1个空格分隔，行的首尾不得有多余空格。
若不存在“食物链”，输出“No Solution”。

输入样例1：
5
-LWDW
W-LDW
WW-LW
DWW-W
DDLW-
输出样例1：
1 3 5 4 2
输入样例2：
5
-WDDW
D-DWL
DD-DW
DDW-D
DDDD-
输出样例2：
No Solution
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int *a,n;
int flag=0;
void dfs(int num,int deep)
{
	if(flag==1) return;
	a[deep]=num;
	if(deep==n-1&&find(v[num].begin(),v[num].end(),a[0])!=v[num].end())
	{
		cout<<a[0]+1;
		for(int i=1;i<n;i++)
		{
			cout<<' '<<a[i]+1;
		}
		flag=1;
		return ;
	}
	for(int i=0;i<v[num].size();i++)
	{
		if(find(a,a+deep,v[num][i])==a+deep) 
		{
			dfs(v[num][i],deep+1);
		}
	}
	
}
int main()
{
	
	char c;	
	cin>>n;
	a=new int[n];
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c;
			if(c=='L') v[j].push_back(i);
			else if(c=='W') v[i].push_back(j);
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(int i=0;i<n;i++)
	{	for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]+1<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<v[0].size();i++)
	{
		a[0]=0;
		dfs(v[0][i],1);
	}
	if(flag==0) cout<<"No Solution";
	return 0;
}

