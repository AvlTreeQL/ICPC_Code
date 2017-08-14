/*

���⣺��Խ����

X�ǵ�̹��ս������֣������뽻��ش�Խ�������������͸��������������ܱ���������ת�����򽫱��ϡ�
ĳ̹����Ҫ��A����B��ȥ��A��B�������ǰ�ȫ����û���������������������������߲���·����̣�

��֪�ĵ�ͼ��һ��������������ĸ�����A��B�������������������Ż򸺺ŷֱ��ʾ����������������
���磺
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

̹�˳�ֻ��ˮƽ��ֱ�������ƶ������ڵ�����

���ݸ�ʽҪ��

�����һ����һ������n����ʾ����Ĵ�С�� 4<=n<100
��������n�У�ÿ����n�����ݣ�������A��B��+��-�е�ĳһ�����м��ÿո�ֿ���
A��B��ֻ����һ�Ρ�

Ҫ�����һ����������ʾ̹�˴�A����B���������ƶ�������
���û�з����������-1

���磺
�û����룺
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

�����Ӧ�������
10

��ԴԼ����
��ֵ�ڴ����� < 512M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�

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
