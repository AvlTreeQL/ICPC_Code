/*

标题：穿越雷区

X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。
某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？

已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。
例如：
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

坦克车只能水平或垂直方向上移动到相邻的区。

数据格式要求：

输入第一行是一个整数n，表示方阵的大小， 4<=n<100
接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。
A，B都只出现一次。

要求输出一个整数，表示坦克从A区到B区的最少移动步数。
如果没有方案，则输出-1

例如：
用户输入：
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

则程序应该输出：
10

资源约定：
峰值内存消耗 < 512M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/
#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	int x;
	int y;
	int step;
	node(){
		x=0;
		y=0;
		step=0;
	}
	node(int a,int b,int c)
	{
		x=a;
		y=b;
		step=c;
	}
};
int N;
int x,y,xx,yy;
char a[101][101];
void bfs(int x,int y)
{
	queue<node> q;
	q.push(node(x,y,0));
	node head,tail;
	int dir[4][2]={0,1,0,-1,1,0,-1,0};
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		if(head.x==xx&&head.y==yy)
		{
			cout<<head.step<<endl;
			break;
		}
		if(a[head.x][head.y]=='+')
		{
			for(int i=0;i<4;i++)
			{
				int x=head.x+dir[i][0];
				int y=head.y+dir[i][1];
				
				if(x<0||x>=N||y<0||y>=N||a[x][y]=='+') continue;
				q.push(node(x,y,head.step+1)); 
			}
		}
		else 
		{
			for(int i=0;i<4;i++)
			{
				int x=head.x+dir[i][0];
				int y=head.y+dir[i][1];
				
				if(x<0||x>=N||y<0||y>=N||a[x][y]=='-') continue;
				q.push(node(x,y,head.step+1)); 
			}
		}
	}
	
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='A')
				x=i,y=j;
			else if(a[i][j]=='B')
				xx=i,yy=j;
		}
	}
	bfs(x,y);
	return 0;
} 
