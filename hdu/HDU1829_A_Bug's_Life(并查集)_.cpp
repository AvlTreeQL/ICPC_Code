/*
Background 
Professor Hopper is researching the sexual behavior of a rare species of bugs. 
He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. 
In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs. 
Problem 
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input
The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output
The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.
Sample Input
4
3 3
1 2
2 3
1 3
4 2
1 2
3 4
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Sample Output
Scenario #1:
Suspicious bugs found!

Scenario #2:
No suspicious bugs found!
*/
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 1111
using namespace std;
int f[2000010];
void init(int n)
{  
	for(int i=1;i<=INF+n;i++)
		f[i] = i;   
}  
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool unin(int a,int b)
{
	int a1=find(a);
	int b1=find(b-INF);
	if(a1==b1)
	{
		return false;
	}
	b1=find(b);
	if(a1!=b1)
	{
		f[a1]=f[b1];
		return false;
	}
	return false;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int n,k,a,b,ans=0;
		scanf("%d%d",&n,&k);
		init(n);
		while(k--)
		{
			scanf("%d%d",&a,&b);
			if(!ans&&!unin(a,b+INF)&&!unin(b,a+INF))
			{
				ans++;
			}
		}
		if(ans)printf("%s%d%c\n%s\n","Scenario #",i,':',"Suspicious bugs found!");
		else printf("%s%d%c\n%s\n","Scenario #",i,':',"No suspicious bugs found!");
		if(i!=N)printf("\n");
	}
	return 0;
}
/*
Background 
Professor Hopper is researching the sexual behavior of a rare species of bugs. 
He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. 
In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs. 
Problem 
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input
The first line of the input contains the number of scenarios. 
Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output
The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.
Sample Input
4
3 3
1 2
2 3
1 3
4 2
1 2
3 4
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Sample Output
Scenario #1:
Suspicious bugs found!

Scenario #2:
No suspicious bugs found!
*/
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 1111
using namespace std;    
int f[200010];  
bool flag;    
void init(int n)
{     
    for(int i=1;i<=INF+n;++i)f[i]=i;  
    flag=true;  
}  

int find(int x)
{  
    if(x!=f[x]) f[x]=find(f[x]);  
    return f[x];  
}  
  
void unin(int a,int b)
{  
    int a1,b1;  
    a1=find(a);  
    b1=find(b-INF);        
    if(a1==b1)
	{  
        flag=false;  
        return;  
    }
    b1=find(b);  
    if(a1!=b1)
	{  
        f[a1]=f[b1];  
    }  
}  
  
int main()
{   
    int N,n,k,a,b;  
    scanf("%d",&N);  
    for(int i=1;i<=N;++i)
	{  
        scanf("%d%d",&n,&k);  
        init(n);  
        for(int j=1;j<=k;++j)
		{  
            scanf("%d%d",&a,&b);  
            if(flag)
			{  
                unin(a,b+INF);  
                unin(b,a+INF);  
            }  
        }  
        if(!flag)printf("%s%d%c\n%s\n","Scenario #",i,':',"Suspicious bugs found!");
		else printf("%s%d%c\n%s\n","Scenario #",i,':',"No suspicious bugs found!");
		if(i!=N)printf("\n");
    }  
    return 0;  
}  
