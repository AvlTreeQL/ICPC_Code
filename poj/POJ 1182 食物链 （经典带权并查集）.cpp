/*
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述： 
第一种说法是"1 X Y"，表示X和Y是同类。 
第二种说法是"2 X Y"，表示X吃Y。 
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。 
1） 当前的话与前面的某些真的话冲突，就是假话； 
2） 当前的话中X或Y比N大，就是假话； 
3） 当前的话表示X吃X，就是假话。 
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 
Input
第一行是两个整数N和K，以一个空格分隔。 
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。 
若D=1，则表示X和Y是同类。 
若D=2，则表示X吃Y。
Output
只有一个整数，表示假话的数目。
Sample Input
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
Sample Output
3
*/
#include<bits/stdc++.h>
using namespace std;
const int Max=50010;
int fat[Max],ran[Max];
void Init(int n)//初始化重要
{
    for(int i=0; i<=n; i++)
    {
        fat[i]=i;//初始化都是指向（看做）自己
        ran[i]=0;//0同类 1吃父节点 2被父节点吃
    }
    return;
}
int Find(int x)//找寻父节点+路径压缩
{
    if(x==fat[x])
        return fat[x];
    int y=Find(fat[x]);
        ran[x]=(ran[x]+ran[fat[x]])%3;//递归后从祖先节点向后到每个孩子来计算
    return fat[x]=y;//路径压缩
}
int Union(int typ,int x,int y)//区间并与查询
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)//共父节点才能判断出关系
    {
        if((ran[x]-ran[y]+3)%3==typ-1)
            return 0;
        return 1;
    }
    fat[x1]=y1;//连接两父节点
    ran[x1]=(typ-1+ran[y]-ran[x]+3)%3;//使用类似向量方法来计算权值,虽然题目只有两个，但是会出现被吃这种情况，所以要变成3种情况，注意一定要处理负数的情况
    return 0;
}
int main()
{
    int n,k,ans;
    int typ,smt1,smt2;
    scanf("%d %d",&n,&k);
        Init(n);
        ans=0;
        for(int i=0; i<k; i++)
        {
            scanf("%d %d %d",&typ,&smt1,&smt2);
            if(smt1==smt2&&typ==2)
                ans++;
            else if(smt1>n||smt2>n)
                ans++;
            else
                ans+=Union(typ,smt1,smt2);
        }
        printf("%d\n",ans);
    return 0;
}
