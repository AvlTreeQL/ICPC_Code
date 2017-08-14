/*
You are trapped in a 3D dungeon and need to find the quickest way out! 
The dungeon is composed of unit cubes which may or may not be filled with rock. 
It takes one minute to move one unit north, south, east, west, up or down. 
You cannot move diagonally and the maze is surrounded by solid rock on all sides. 

Is an escape possible? If yes, how long will it take? 
Input
The input consists of a number of dungeons. 
Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size). 
L is the number of levels making up the dungeon. 
R and C are the number of rows and columns making up the plan of each level. 
Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. 
A cell full of rock is indicated by a '#' and empty cells are represented by a '.'. Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.
Output
Each maze generates one line of output. If it is possible to reach the exit, print a line of the form 
Escaped in x minute(s).

where x is replaced by the shortest time it takes to escape. 
If it is not possible to escape, print the line 
Trapped!
Sample Input
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
Sample Output
Escaped in 11 minute(s).
Trapped!
*/
#include<iostream>
#include<cstring>
#define MAX 65536
using namespace std;
char MAP[31][31][31];
bool visit[31][31][31],flag;
int s_x,s_y,s_z;
int e_x,e_y,e_z;
int a,b,c;
int MIN;
void DFS(int x,int y,int h,int deep)
{
	if(x<0||y<0||h<0||x>=b||y>=c||h>=a||deep>=MIN||visit[h][x][y]||MAP[h][x][y]=='#') return ;
	visit[h][x][y]=true;
	if(x==e_x&&y==e_y&&h==e_z)
	{
		flag=true;
		if(deep<MIN)
		MIN=deep;
		visit[h][x][y]=false;
		return ;
	}
	DFS(x+1,y,h,deep+1);
	DFS(x-1,y,h,deep+1);
	DFS(x,y+1,h,deep+1);
	DFS(x,y-1,h,deep+1);
	DFS(x,y,h+1,deep+1);
	DFS(x,y,h-1,deep+1);
	visit[h][x][y]=false;
}
int main()
{
	while(1)
	{
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0)
			break;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<c;k++)
				{
					cin>>MAP[i][j][k];
					if(MAP[i][j][k]=='S')
					{
						s_x=j;
						s_y=k;
						s_z=i;
					}
					else if(MAP[i][j][k]=='E')
					{
						e_x=j;
						e_y=k;
						e_z=i;
					}
				}
			}
		}
		memset(visit,false,sizeof(visit));
		flag=false;
		MIN=MAX;
		DFS(s_x,s_y,s_z,0);
		if(flag)
			cout<<"Escaped in "<<MIN<<" minute(s)."<<endl;
		else 
			cout<<"Trapped!"<<endl;
	}
	return 0;
}

