/*
1459 �Թ���Ϸ
��׼ʱ�����ƣ�1 �� �ռ����ƣ�131072 KB ��ֵ: 0 �Ѷȣ�������
������һ���Թ�ǰ�����Թ������ɸ�������ɣ�ÿ�����䶼��һ���÷֣���һ�ν���������䣬��Ϳ��Եõ������������������˫���·������Щ���䣬��������Щ��·��һ�������ߵ�����һ��������ҪһЩʱ�䡣��Ϸ�涨����������յ㷿�䣬����ҪĿ���Ǵ���㾡�쵽���յ㣬��������ҪĿ���ǰ���£�ʹ����ĵ÷��ܺ;����ܴ������������ˣ��������䡢��·�������������յ��ȫ����Ϣ�����ܼ����ھ����뿪�Թ���ǰ���£�������÷��Ƕ���ô��
Input
��һ��4������n (<=500), m, start, end��n��ʾ����ĸ����������Ŵ�0��(n - 1)��m��ʾ��·��,������������֮�����ֻ��һ����·��start��end��ʾ�����յ㷿��ı�š�
�ڶ��а���n���ո�ָ���������(������600)����ʾ����ÿ��������ĵ÷֡�
�ٽ�����m�У�ÿ��3���ո�ָ�������x, y, z (0<z<=200)��ʾ��·,��ʾ�ӷ���x������y(˫��)�ĵ�·,ע�⣬���ֻ��һ����·������������, ����Ҫ��ʱ��Ϊz��
���뱣֤��start��end������һ��·����
Output
һ�У������ո�ָ�����������һ����ʾ��������Ҫ��ʱ�䣬�ڶ�����ʾ��������ʱ��ǰ���¿��Ի�õ����÷֡�
Inputʾ��
3 2 0 2
1 2 3
0 1 10
1 2 11
Outputʾ��
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
