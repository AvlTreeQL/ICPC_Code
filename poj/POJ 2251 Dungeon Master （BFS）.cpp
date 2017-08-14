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
#include<queue>
#define MAX 65536
using namespace std;
class node
{
public:
	int x;
	int y;
	int z;
	int time;
	node()
	{	
		x=0;
		y=0;
		z=0;
		time=0;
	}
	node(int a,int b,int c)
	{
		x=a;
		y=b;
		z=c;
		time=0;
	}
};
char MAP[31][31][31];
bool visit[31][31][31],flag;
int s_x,s_y,s_z,e_x,e_y,e_z,a,b,c;
int MIN;
int dir[][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
void BFS(int x,int y,int h)
{
	queue<node> q;
	q.push(node(x,y,h));
	node head,tail;
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		if(head.x==e_x&&head.y==e_y&&head.z==e_z)
		{
			flag=true;
			MIN=head.time;
			return ;
		}
		for(int i=0;i<6;i++)
		{
			tail.x=head.x+dir[i][0];
			tail.y=head.y+dir[i][1];
			tail.z=head.z+dir[i][2];
			tail.time=head.time+1;
			if(!(tail.x<0||tail.y<0||tail.z<0||tail.x>=b||tail.y>=c||tail.z>=a||visit[tail.z][tail.x][tail.y]||MAP[tail.z][tail.x][tail.y]=='#'))
			{
				visit[tail.z][tail.x][tail.y]=true;
				q.push(tail);
			}
		}
	}

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
		BFS(s_x,s_y,s_z);
		if(flag)
			cout<<"Escaped in "<<MIN<<" minute(s)."<<endl;
		else 
			cout<<"Trapped!"<<endl;
	}
	return 0;
}

