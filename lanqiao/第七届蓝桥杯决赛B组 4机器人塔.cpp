/*
��������

X����Ļ����˱��������������ַ�װ��A��B��
������α��ݵ��Ǵ����������

���ƣ�

     A
    B B
   A B A
  A A B B
 B B B A B
A B A B B A

���ڵ����������ǣ�
  
  A ֻ��վ�� AA �� BB �ļ��ϡ�
  B ֻ��վ�� AB �� BA �ļ��ϡ�

��������ǰ��������Ӽ���һ�£��ڸ���A��B������ʱ��������ɶ����ֻ���������

����һ���������� M �� N���ո�ֿ���0<M,N<500��,�ֱ��ʾA��B����������֤���������ԡ�

Ҫ�����һ����������ʾ���Բ����Ļ���������

���磺
�û����룺
1 2

����Ӧ�������
3


�����磺
�û����룺
3 3

����Ӧ�������
4

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 1000ms

���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�
#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int ans = 0;
char ch[500][500];

//���ڽ���dp�Ż� 
int flag[500][500][500] = {0};
bool dp[500][500][500];

//�ж�m��A��n��B�Ƿ�����ɸ߶�ΪH�����ǵĵ�h�� 
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

//����ײ����������о� 
void dfs(int m, int n, int i){
    if(i == H)
	{
        if(search(m, n, 1))
		{
            ++ ans;
            //�������
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
