/*
Description

A university network is composed of N computers. 
System administrators gathered information on the traffic between nodes, 
and carefully divided the network into two subnetworks in order to minimize traffic between parts.
A disgruntled computer science student Vasya, after being expelled from the university, decided to have his revenge. 
He hacked into the university network and decided to reassign computers to maximize the traffic between two subnetworks.
Unfortunately, he found that calculating such worst subdivision is one of those problems he, being a student, failed to solve.
So he asks you, a more successful CS student, to help him.
The traffic data are given in the form of matrix C, where Cij is the amount of data sent between ith and jth nodes (Cij = Cji, Cii = 0). 
The goal is to divide the network nodes into the two disjointed subsets A and B so as to maximize the sum ��Cij (i��A,j��B).
 
Input

The first line of input contains a number of nodes N (2 <= N <= 20). The following N lines, containing N space-separated integers each, represent the traffic matrix C (0 <= Cij <= 10000).
Output file must contain a single integer �� the maximum traffic between the subnetworks.

Output

Output must contain a single integer �� the maximum traffic between the subnetworks.

Sample Input

3
0 50 30
50 0 40
30 40 0
 

Sample Output

90
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
using namespace std;
int a[30][30];      //map
bool con[30];       //����������
int ans,n;

void dfs(int id,int tmp)    //��id�Ƶ��ұߣ���������
{
    int old=tmp;
    con[id]=true;
    for(int i=0; i<n; i++)  //ͬ����������
    {
        if(con[i])tmp-=a[i][id];
        else tmp+=a[i][id];
    }
    ans=max(ans,tmp);
    for(int i=id+1; i<n; i++)   //��������ĵ�
        if(!con[i]&&tmp>old)
            dfs(i,tmp);
    con[id]=false;
}

int main()
{
    while(~scanf("%d",&n))
    {
        ans=0;
        memset(con,false,sizeof(con));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        for(int i=0; i<n; i++)
            dfs(i,0);
        printf("%d\n",ans);
    }
    return 0;
}
/*����

����һЩ��������֮���������ĵ�����������Ҫ����Щ���Ϊ���飬ͬһ��ĵ�֮����������ģ���ͬ��ĵ�֮����Ҫ�������������������ĵ��������ֵ��

˼·

�����������

�����ȼ������е㶼����ߣ����ڰ����еĵ��õ��ұߣ�����ͬ��ĵ���Ҫ��ȥ����֮�����������ͬ��ĵ������Щ������Ȼ��������ֵ��

���һ���㱻�õ��ұߣ��ı�֮�������ֵС����֮ǰ������ֵ����Ҫ�����������ƶ����ұߣ��ò�ݹ������
��Ϊ�������ǿ��Խ����ģ������ı仯����Գ��ԡ�
*/
