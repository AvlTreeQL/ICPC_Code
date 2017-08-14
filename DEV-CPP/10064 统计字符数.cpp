#include<stdio.h>
int main()
{
	int n,i;
	char a[30][30];
	void fun(char *a);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	for(i=0;i<n;i++)
		fun(a[i]);
	return 0;
}
void fun(char *a)
{
	int i,j,t,num,max=0;
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0,num=0;a[j]!='\0';j++)
		{
			if(a[i]==a[j])
			{
				num++;
				if(num>max)
				{
					max=num;
					t=i;
				}
			}
		}
	}
	printf("%c %d\n",a[t],max);
}
/*
【问题描述】判断一个由a-z 这26个字符组成的字符串中哪个字符出现的次数最多。
【输入形式】第1行是测试数据的组数n,每组测试数据占1行，是一个由a-z这26个字符组成的字符串，每行数据不超过
                        1000个字符且非空。
【输出形式】输出n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数，中间是一个
                        空格。如果有多个字符出现的次数相同且最多，那么输出ASCII码最小的那一个字符。
【样例输入】
2
abbccc
adfadffasdf
【样例输出】c 3
            f 4
【样例说明】输出样例如上。
【评分标准】本题共4个测试点，每个测试点0.25分，共1.0分。
*/