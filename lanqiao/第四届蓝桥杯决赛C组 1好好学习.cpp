/*

标题：好好学习

    汤姆跟爷爷来中国旅游。
	一天，他帮助中国的小朋友贴标语。
	他负责贴的标语是分别写在四块红纸上的四个大字：“好、好、学、习”。
	但是汤姆不认识汉字，他就想胡乱地贴成一行。

    请你替小汤姆算一下，他这样乱贴，恰好贴对的概率是多少？

    答案是一个分数，请表示为两个整数比值的形式。例如：1/3 或 2/15 等。
	
	如果能够约分，请输出约分后的结果。

    注意：不要书写多余的空格。


    请严格按照格式，通过浏览器提交答案。
    注意：只提交这个比值，不要写其它附加内容，比如：说明性的文字。
answer:1/12
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<4*3*2*1<<endl;
	return 0;
}        
*/
#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
    int i,a[4]={1,1,2,3},cnt=0,s=0;  
    do  
    {  
        cnt++;  
        if (a[0]==1&&a[1]==1&&a[2]==2&&a[3]==3)  
        s++;  
    }while (next_permutation(a,a+4));  
    cout<<s<<"/"<<cnt;  
    return 0;  
}  
