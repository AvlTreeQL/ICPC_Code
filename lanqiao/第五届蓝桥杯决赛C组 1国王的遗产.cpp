/*

标题：国王的遗产

    X国是个小国。国王K有6个儿子。在临终前，K国王立下遗嘱：国王的一批牛作为遗产要分给他的6个儿子。
    其中，大儿子分1/4，二儿子1/5，三儿子1/6，....
    直到小儿子分1/9。
    牛是活的，不能把一头牛切开分。

    最后还剩下11头牛，分给管家。

    请计算国王这批遗产中一共有多少头牛。

    这是一个整数，请通过浏览器提交答案，不要填写任何多余的内容（比如说明性的文字）
错误做法
#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=1439;1;i++)
	{
		int sum=i;
		sum-=i/4;
		sum-=i/5;
		sum-=i/6;
		sum-=i/7;
		sum-=i/8;
		sum-=i/9;
		if(sum==11)
		{
			cout<<i<<' '<<i/4<<' '<<i/5<<' '<<i/6<<' '<<i/7<<' '<<i/8<<' '<<i/9<<endl;
			break;
		}
	}
	return 0;
} 
answer:2520
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=1439;1;i++)
	{
		int sum=i; 
		if(i%4==0&&i%5==0&&i%6==0&&i%7==0&&i%8==0&&i%9==0)
		{
			if(sum-i/4-i/5-i/6-i/7-i/8-i/9==11)
			{
				cout<<i<<' '<<i/4<<' '<<i/5<<' '<<i/6<<' '<<i/7<<' '<<i/8<<' '<<i/9<<endl;
				break;
			}
		} 
	}
	return 0;
} 
