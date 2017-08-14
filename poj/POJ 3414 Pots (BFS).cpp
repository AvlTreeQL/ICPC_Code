/*
Description

You are given two pots, having the volume of A and B liters respectively. The following operations can be performed:

FILL(i)        fill the pot i (1 �� i �� 2) from the tap;
DROP(i)      empty the pot i to the drain;
POUR(i,j)    pour from pot i to pot j; after this operation either the pot j is full (and there may be some water left in the pot i), or the pot i is empty (and all its contents have been moved to the pot j).
Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.

 

Input

On the first and only line are the numbers A, B, and C. These are all integers in the range from 1 to 100 and C��max(A,B).

 

Output

The first line of the output must contain the length of the sequence of operations K. 
The following K lines must each describe one operation. 
If there are several sequences of minimal length, output any one of them. If the desired result can��t be achieved, the first and only line of the file must contain the word ��impossible��.

 

Sample Input

3 5 4
 

Sample Output

6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)
 

����

���������ӣ��ֱ����������Ȼ�����Ƕ������������ֲ�����

����1��2����
����1��2����
��1����2���2����1
�ʣ���ô�������ٵĲ�����������ĳһ�����Ӹպôﵽָ������

 

˼·

���ǿ�����Ϊ��ʼ״̬�������Ӷ��ǿյģ�Ȼ�����ÿһ�ֲ���������һ��״̬������������У�Ȼ��Զ����е�����״̬�ٽ�����һ�β�����Ҳ����bfs����

������Ҫע����ǣ����ǲ�����ͬһ��״̬������������Σ���ֹ��ջ�������Ҫ����һЩ����֪a,bС��100����˿�����һ����ά�������洢ĳ��״̬�Ƿ񱻷��ʹ���

���������̵Ĳ��������벽�衣

Ҳ��֪������Ϊ��ͼ�������򵥻���ʲô�����еĲ�������һ���������жϣ������������Գ�������
*/
#include <iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;
typedef __int64 LL;
bool visited[105][105];

struct node
{
    int left;
    int right;
    int time;
    string path;
    void init(int left,int right,string path,int time)
    {
        this->left=left;
        this->right=right;
        this->path=path;
        this->time=time;
    }
};
void bfs(int left,int right,int c)
{
    queue<node>sk;
    bool flag=false;
    node s;
    s.init(0,0,"",0);
    visited[0][0]=true;
    sk.push(s);
    while(!sk.empty())
    {
        node p=sk.front();
        sk.pop();
        if(p.left==c||p.right==c)
        {
            cout<<p.time<<endl<<p.path;
            flag=true;
            return;
        }
        node tmp;
        if(!visited[left][p.right])     //����1
        {
            tmp.init(left,p.right,p.path+"FILL(1)\n",p.time+1);
            visited[left][p.right]=true;
            sk.push(tmp);
        }
        if(!visited[p.left][right])     //����2
        {
            tmp.init(p.left,right,p.path+"FILL(2)\n",p.time+1);
            visited[p.left][right]=true;
            sk.push(tmp);
        }
        if(!visited[0][p.right])        //�ͷ�1
        {
            tmp.init(0,p.right,p.path+"DROP(1)\n",p.time+1);
            visited[0][p.right]=true;
            sk.push(tmp);
        }
        if(!visited[p.left][0])         //�ͷ�2
        {
            tmp.init(p.left,0,p.path+"DROP(2)\n",p.time+1);
            visited[p.left][0]=true;
            sk.push(tmp);
        }

        if(left-p.left<p.right&&!visited[left][p.right-(left-p.left)])  //��2��1
        {
            tmp.init(left,p.right-(left-p.left),p.path+"POUR(2,1)\n",p.time+1);
            visited[left][p.right-(left-p.left)]=true;
            sk.push(tmp);
        }
        else if(left-p.left>=p.right&&!visited[p.left+p.right][0])
        {
            tmp.init(p.left+p.right,0,p.path+"POUR(2,1)\n",p.time+1);
            visited[p.left+p.right][0]=true;
            sk.push(tmp);
        }

        if(p.left<=right-p.right&&!visited[0][p.left+p.right])          //��1��2
        {
            tmp.init(0,p.left+p.right,p.path+"POUR(1,2)\n",p.time+1);
            visited[0][p.left+p.right]=true;
            sk.push(tmp);
        }
        else if(p.left>right-p.right&&!visited[p.left-(right-p.right)][right])
        {
            tmp.init(p.left-(right-p.right),right,p.path+"POUR(1,2)\n",p.time+1);
            visited[p.left-(right-p.right)][right]=true;
            sk.push(tmp);
        }
    }
    if(!flag)
        printf("impossible\n");
}
int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        memset(visited,false,sizeof(visited));
        bfs(a,b,c);
    }
}
