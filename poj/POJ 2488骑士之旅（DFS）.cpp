#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;
bool visited[30][30],flag;

int move[8][2]= {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int p,q;

struct node
{
    char x;
    char y;
    void init(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
} sk[1005];

void dfs(int x,int y,int deep)
{
    if(deep==p*q)       //已经走遍了所有格
    {
        for(int i=0; i<deep; i++)
            printf("%c%c",sk[i].x,sk[i].y);
        printf("\n");
        flag=true;      //找到路径
        return;
    }
    for(int i=0; i<8; i++)
    {
        int xi=move[i][0]+x;
        int yi=move[i][1]+y;
        if(xi<0||xi>=p||yi<0||yi>=q)continue;   //棋盘外
        if(visited[xi][yi]==false)              //该位置为空
        {
            visited[xi][yi]=true;
            sk[deep].init(yi+'A',xi+'1');
            dfs(xi,yi,deep+1);
            if(flag)return;
            visited[xi][yi]=false;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int ni=1; ni<=n; ni++)
    {       
        scanf("%d%d",&p,&q);
		printf("Scenario #%d:\n",ni);
        flag=false;         //当前未找到路径
        memset(visited,false,sizeof(visited));
        for(int j=0; j<q; j++)      //先枚举列是为了保证字典序最小
            for(int i=0; i<p; i++)
            {
                visited[i][j]=true;
                sk[0].init(j+'A',i+'1');
                dfs(i,j,1);
                visited[i][j]=false;
            }
        if(!flag)       //没有找到路径
            printf("impossible\n");
        if(ni!=n)puts("");
    }
    return 0;
}
