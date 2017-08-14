/*

标题：六角幻方

    把 1 2 3 ... 19 共19个整数排列成六角形状，如下：

    * * *             
   * * * *
  * * * * *
   * * * * 
    * * *

	0 1 2
   3 4 5 6
  7 8 9 0 1
   2 3 4 5 
    6 7 8 
      
	15 13 10 
   14 8 4 12 
   9 6 5 2 16
   11 1 7 19 
    18 17 3 0 0 0


    要求每个直线上的数字之和必须相等。共有15条直线哦！

    再给点线索吧！我们预先填好了2个数字，第一行的头两个数字是：15 13，参见图【p1.png】，黄色一行为所求。

    请你填写出中间一行的5个数字。数字间用空格分开。

    这是一行用空格分开的整数，请通过浏览器提交答案，不要填写任何多余的内容（比如说明性的文字等）

	answer:9 6 5 2 16

*/

#include <bits/stdc++.h>
using namespace std; 
int a[19]={15,13};
//int a[19]={15,13,10,14,8,4,12,9,6,5,2,16,11,1,7,19,18,17,3};
void check()
{
	int sum[15];
	sum[0]=a[0]+a[1]+a[2];
	sum[1]=a[3]+a[4]+a[5]+a[6];
	sum[2]=a[7]+a[8]+a[9]+a[10]+a[11];
	sum[3]=a[12]+a[13]+a[14]+a[15];
	sum[4]=a[16]+a[17]+a[18];
	
	sum[5]=a[0]+a[3]+a[7];
	sum[6]=a[1]+a[4]+a[8]+a[12];
	sum[7]=a[2]+a[5]+a[9]+a[13]+a[16];
	sum[8]=a[6]+a[10]+a[14]+a[17];
	sum[9]=a[11]+a[15]+a[18];
	
	sum[10]=a[2]+a[6]+a[11];
	sum[11]=a[1]+a[5]+a[10]+a[15];
	sum[12]=a[0]+a[4]+a[9]+a[14]+a[18];
	sum[13]=a[3]+a[8]+a[13]+a[17];
	sum[14]=a[7]+a[12]+a[16];
	for(int i=1;i<15;i++)
	{
		if(sum[0]!=sum[i]) return ;
	}
	cout<<a[7]<<' '<<a[8]<<' '<<a[9]<<' '<<a[10]<<' '<<a[11]<<endl;
	system("pause");
}
bool visit[19];

void dfs(int deep)  //一定要剪枝 
{
	if (deep== 7)  
    {  
        if (28+a[2] != a[3]+a[4]+a[5]+a[6]) return;  
    }  
    if (deep== 8)  
    {  
        if (28+a[2] != 15+a[3]+a[7]) return;   
    }   
    if (deep== 12)  
    {  
        if (28+a[2] != a[7]+a[8]+a[9]+a[10]+a[11]) return;  
    }  
    if (deep== 13)  
    {  
        if (28+a[2] != 13+a[4]+a[8]+a[12]) return;  
    }  
    if (deep== 16)  
    {  
        if (28+a[2] != a[12]+a[13]+a[14]+a[15]) return;  
    }  
    if (deep== 17)  
    {  
        if (28+a[2] != a[2]+a[5]+a[9]+a[13]+a[16]) return;  
        if (28+a[2] != a[7]+a[12]+a[16]) return;  
    }  
    if (deep== 18)  
    {  
        if (28+a[2] != a[6]+a[10]+a[14]+a[17]) return;  
        if (28+a[2] != a[3]+a[8]+a[13]+a[17]) return;  
    }  
	if(deep==19)
	{
		check();
		return ;
	}
	for(int i=1;i<=19;i++)
	{
		if(!visit[i])
		{
			a[deep]=i;
			visit[i]=true;
			dfs(deep+1);
			visit[i]=false;
		}
	}
}
int main()
{
	visit[15]=visit[13]=true;
	dfs(2);
	return 0;
}
