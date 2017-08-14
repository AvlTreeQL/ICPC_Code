/*
Farmer John knows that an intellectually satisfied cow is a happy cow who will give more milk. He has arranged a brainy activity for cows in which they manipulate an M ¡Á N grid (1 ¡Ü M ¡Ü 15; 1 ¡Ü N ¡Ü 15) of square tiles, each of which is colored black on one side and white on the other side.

As one would guess, when a single white tile is flipped, it changes to black; when a single black tile is flipped, it changes to white. The cows are rewarded when they flip the tiles so that each tile has the white side face up. However, the cows have rather large hooves and when they try to flip a certain tile, they also flip all the adjacent tiles (tiles that share a full edge with the flipped tile). Since the flips are tiring, the cows want to minimize the number of flips they have to make.

Help the cows determine the minimum number of flips required, and the locations to flip to achieve that minimum. If there are multiple ways to achieve the task with the minimum amount of flips, return the one with the least lexicographical ordering in the output when considered as a string. If the task is impossible, print one line with the word "IMPOSSIBLE".

Input
Line 1: Two space-separated integers: M and N 
Lines 2.. M+1: Line i+1 describes the colors (left to right) of row i of the grid with N space-separated integers which are 1 for black and 0 for white
Output
Lines 1.. M: Each line contains N space-separated integers, each specifying how many times to flip that particular location.
Sample Input
4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1
Sample Output
0 0 0 0
1 0 0 1
1 0 0 1
0 0 0 0
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
class node
{
public:   
	int l;
    int r;
    int step;
    string path;
    node(){ }
    node(int a,int b,string s,int n)
    {
        l=a;
        r=b;
        path=s;
        step=n;
    }
    bool operator<(const node &b)const  
    {  
        if(l==b.l)  
            return r<b.r;  
        else  
            return l<b.l;  
    } 
};
int cup1,cup2,cc;
map<node,bool> visit;
map<int,int> ll;
map<int,int> rr;
map<int,string> ss;

void init(node p)
{ 	
	ll[0]=cup1,rr[0]=p.r,ss[0]="FILL(1)\n";
	ll[1]=p.l,rr[1]=cup2,ss[1]="FILL(2)\n";
	ll[2]=0,rr[2]=p.r,ss[2]="DROP(1)\n";
	ll[3]=p.l,rr[3]=0,ss[3]="DROP(2)\n";
	if(cup1-p.l<p.r)
		ll[4]=cup1,rr[4]=p.r-(cup1-p.l),ss[4]="POUR(2,1)\n";
	else
		ll[4]=p.l+p.r,rr[4]=0,ss[4]="POUR(2,1)\n";
	if(p.l>cup2-p.r)
		ll[5]=p.l-(cup2-p.r),rr[5]=cup2,ss[5]="POUR(1,2)\n";
	else
		ll[5]=0,rr[5]=p.l+p.r,ss[5]="POUR(1,2)\n";
}
void bfs(int cup1,int cup2,int cc)
{
	queue<node> q;
	bool flag=false;
	node s(0,0,"",0),head;
	q.push(s);
	visit[s]=true;
	
	while(!q.empty())
	{
		head=q.front();
		q.pop();
//		cout<<'*'<<head.l<<' '<<head.r<<' '<<endl<<endl;
		if(head.l==cc||head.r==cc)
		{
			cout<<head.step<<endl;
			cout<<head.path;
			flag=true;
			return ;
		}
		init(head);
		
		for(int i=0;i<6;i++)
		{
			node tail(ll[i],rr[i],head.path+ss[i],head.step+1);
//			cout<<tail.l<<' '<<tail.r<<' '<<ss[i]<<endl;
			if(!visit[tail])
			{
				visit[tail]=true;
				q.push(tail);
			}
		}
	}
	if(!flag)
	{
		cout<<"impossible"<<endl;
	}
}

int main()
{
	cin>>cup1>>cup2>>cc;
	bfs(cup1,cup2,cc);
	return 0;
} 
