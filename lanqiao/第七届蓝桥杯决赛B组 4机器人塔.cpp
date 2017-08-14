/*
机器人塔

X星球的机器人表演拉拉队有两种服装，A和B。
他们这次表演的是搭机器人塔。

类似：

     A
    B B
   A B A
  A A B B
 B B B A B
A B A B B A

队内的组塔规则是：
  
  A 只能站在 AA 或 BB 的肩上。
  B 只能站在 AB 或 BA 的肩上。

你的任务是帮助拉拉队计算一下，在给定A与B的人数时，可以组成多少种花样的塔。

输入一行两个整数 M 和 N，空格分开（0<M,N<500）,分别表示A、B的人数，保证人数合理性。

要求输出一个整数，表示可以产生的花样种数。

例如：
用户输入：
1 2

程序应该输出：
3


再例如：
用户输入：
3 3

程序应该输出：
4

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int ans = 0;
char ch[500][500];

//用于进行dp优化 
int flag[500][500][500] = {0};
bool dp[500][500][500];

//判断m个A，n歌B是否能组成高度为H的三角的第h层 
int search(int m, int n, int h)
{
    if(flag[m][n][h] != 0)
	{
        return dp[m][n][h];
    }

    if(h == H)
	{
        flag[m][n][h] = 1;
        return dp[m][n][h] = true;
    }

    for(int i = 0; i < H - h; ++ i)
	{
        if(ch[h - 1][i] == ch[h - 1][i + 1])
		{
            if(m <= 0)
			{
                flag[m][n][h] = 1;
                return dp[m][n][h] = false;
            }
            ch[h][i] = 'A';
            -- m;
        }
        else
		{
            if(n <= 0)
			{
                return dp[m][n][h] = false;
            }
            ch[h][i] = 'B';
            -- n;
        }
    }

    flag[m][n][h] = 1;
    return dp[m][n][h] = search(m, n, h + 1);
}

//对最底层的情况进行列举 
void dfs(int m, int n, int i){
    if(i == H)
	{
        if(search(m, n, 1))
		{
            ++ ans;
            //输出三角
            for(int i = 0; i < H; ++ i){
                for(int j = 0; j < H; ++ j){
                    cout << ch[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    if(m)
	{
        ch[0][i] = 'A';
        dfs(m - 1, n, i + 1);
    }
    if(n)
	{
        ch[0][i] = 'B';
        dfs(m, n - 1, i + 1);
    }
}

int main()
{
    cin >> M >> N;
    for(H = 0; H*(H + 1) != 2*(M + N); ++ H);
    dfs(M, N, 0);
    cout << ans << endl; 
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
char dp[550][550];
int a,b,H,ans=0;
map<pair<int,int>,bool> k; 
char check(int a,int b,int h)
{
	if(h==H)
	{
		ans++;
		/*for(int i=h-1;i>=0;i--)
		{
			for(int j=0;j<h-i;j++)
			{
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
		*/
		return false;
	}
	if(k[make_pair(a,b)]&&(a&&b)) return true;
	int na=a,nb=b;
	for(int i=0;i<H-h;i++)
	{
		if(na&&dp[h-1][i]==dp[h-1][i+1])
		{
			dp[h][i]='A';
			na--;
		}
		else if(nb&&dp[h-1][i]!=dp[h-1][i+1])
		{
			dp[h][i]='B';
			nb--;
		}
		else
		{
			return k[make_pair(a,b)]=true;
		}
		
	}
	check(na,nb,h+1);
}

void dfs(char dp[],int a,int b,int deep)
{
	if(deep==H)
	{
		check(a,b,1);
		return ;
	}
	if(a)
	{
		dp[deep]='A';
		dfs(dp,a-1,b,deep+1);
	}
	if(b)
	{
		dp[deep]='B';
		dfs(dp,a,b-1,deep+1);
	}
}
int main()
{
	cin>>a>>b;
	for(H=0;H*(H+1)!=(a+b)*2;H++);
	dfs(*dp,a,b,0);
	cout<<ans<<endl;
	return 0;
}
