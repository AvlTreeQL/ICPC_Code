/*
1459 迷宫游戏
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题
你来到一个迷宫前。该迷宫由若干个房间组成，每个房间都有一个得分，第一次进入这个房间，你就可以得到这个分数。还有若干双向道路连结这些房间，你沿着这些道路从一个房间走到另外一个房间需要一些时间。游戏规定了你的起点和终点房间，你首要目标是从起点尽快到达终点，在满足首要目标的前提下，使得你的得分总和尽可能大。现在问题来了，给定房间、道路、分数、起点和终点等全部信息，你能计算在尽快离开迷宫的前提下，你的最大得分是多少么？
Input
第一行4个整数n (<=500), m, start, end。n表示房间的个数，房间编号从0到(n - 1)，m表示道路数,任意两个房间之间最多只有一条道路，start和end表示起点和终点房间的编号。
第二行包含n个空格分隔的正整数(不超过600)，表示进入每个房间你的得分。
再接下来m行，每行3个空格分隔的整数x, y, z (0<z<=200)表示道路,表示从房间x到房间y(双向)的道路,注意，最多只有一条道路连结两个房间, 你需要的时间为z。
输入保证从start到end至少有一条路径。
Output
一行，两个空格分隔的整数，第一个表示你最少需要的时间，第二个表示你在最少时间前提下可以获得的最大得分。
Input示例
3 2 0 2
1 2 3
0 1 10
1 2 11
Output示例
21 6

*/
#include<bits/stdc++.h>
#define Max 65535
using namespace std;
int grap[500][500];
int path[500][500];
int n,m,s,e,fen[500];
void Floyd()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                if(grap[j][i]+grap[i][k]<grap[j][k])
                 {
                     grap[j][k]=grap[j][i]+grap[i][k];
                     path[j][k]=path[j][i];
                 }
                else if(grap[j][k]!=0&&grap[j][i]!=0&&grap[i][k]!=0&&grap[j][i]+grap[i][k]==grap[j][k])
                {
					int s1=j;
                	int sum=0;//fen[s1];
                	if(s1!=k)
					{
						do
	                	{
	                		s1=path[s1][k];
	                		sum+=fen[s1];
	                	}while(s1!=k);
                	}
					if(fen[i]>sum-fen[k])
                	{
                		grap[j][k]=grap[j][i]+grap[i][k];
                    	path[j][k]=path[j][i];
                	}
                }
			}	
}
int main()
{
    cin>>n>>m>>s>>e;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i!=j)grap[i][j]=Max;
            else grap[i][j]=0;
            path[i][j]=j;
        }
    for(int i=0;i<n;i++)
    {
        cin>>fen[i];
    }
    for(int i=0;i<m;i++)
    {
        int a,b,temp;
        cin>>a>>b>>temp;
        grap[a][b]=grap[b][a]=temp;
    }
    Floyd();
    cout<<grap[s][e]<<' ';
    int sum=fen[s];
    if(s!=e)
	{
		do
	    {
	        s=path[s][e];
	        sum+=fen[s];
	    }while(s!=e);
    }
	cout<<sum;
    return 0;
}
