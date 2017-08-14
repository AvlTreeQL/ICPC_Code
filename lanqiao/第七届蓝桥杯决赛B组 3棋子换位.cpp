/*
棋子换位

有n个棋子A，n个棋子B，在棋盘上排成一行。
它们中间隔着一个空位，用“.”表示，比如：

AAA.BBB

现在需要所有的A棋子和B棋子交换位置。
移动棋子的规则是：
1. A棋子只能往右边移动，B棋子只能往左边移动。
2. 每个棋子可以移动到相邻的空位。
3. 每个棋子可以跳过相异的一个棋子落入空位（A跳过B或者B跳过A）。

AAA.BBB 可以走法：
移动A ==> AA.ABBB
移动B ==> AAAB.BB

跳走的例子：
AA.ABBB ==> AABA.BB

以下的程序完成了AB换位的功能，请仔细阅读分析源码，填写划线部分缺失的内容。



#include <stdio.h>
#include <string.h>

void move(char* data, int from, int to)
{
	data[to] = data[from];
	data[from] = '.';
}

int valid(char* data, int k)
{
	if(k<0 || k>=strlen(data)) return 0;
	return 1;
}
	
void f(char* data)
{
	int i;
	int tag;
	int dd = 0; // 移动方向
	
	while(1){
		tag = 0;
		for(i=0; i<strlen(data); i++){
			if(data[i]=='.') continue;
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;
			
			if(valid(data, i+dd) && valid(data,i+dd+dd) && data[i+dd]!=data[i] && data[i+dd+dd]=='.'){ 
			//如果能跳... 
				move(data, i, i+dd+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		
		if(tag) continue;
		
		for(i=0; i<strlen(data); i++){
			if(data[i]=='.') continue;
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;			
				 
			if(valid(data, i+dd) && data[i+dd]=='.'){ 
			// 如果能移动...
				if() continue;  //填空位置 
				move(data, i, i+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		
		if(tag==0) break;					
	}
}
	
int main()
{
	char data[] = "AAA.BBB";	
	f(data);
	return 0;
}


注意：只提交划线部分缺少的代码，不要复制已有代码或填写任何多余内容。
valid(data, i+dd+dd) && valid(data,i-dd)&&data[i+dd+dd]==data[i-dd]

AA.ABBB
AABA.BB
AABAB.B
AAB.BAB
A.BABAB
.ABABAB
BA.ABAB
BABA.AB
BABABA.
BABAB.A
BAB.BAA
B.BABAA
BB.ABAA
BBBA.AA
BBB.AAA


*/ 


#include <stdio.h>
#include <string.h>

void move(char* data, int from, int to)
{
	data[to] = data[from];
	data[from] = '.';
}

int valid(char* data, int k)
{
	if(k<0 || k>=strlen(data)) return 0;
	return 1;
}
	
void f(char* data)
{
	int i;
	int tag;
	int dd = 0; // 移动方向
	
	while(1){
		tag = 0;
		for(i=0; i<strlen(data); i++){
			if(data[i]=='.') continue;
			
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;
			
			if(valid(data, i+dd) && valid(data,i+dd+dd) 
			&& data[i+dd]!=data[i] && data[i+dd+dd]=='.'){ 
			//如果能跳... 
				move(data, i, i+dd+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		
		if(tag) continue;
		
		for(i=0; i<strlen(data); i++){
			if(data[i]=='.') continue;
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;			
				 
			if(valid(data, i+dd) && data[i+dd]=='.'){ 
			// 如果能移动...
				if(valid(data, i+dd+dd) && valid(data,i-dd)&&data[i+dd+dd]==data[i-dd]) continue; //填空位置 
				move(data, i, i+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		
		if(tag==0) break;					
	}
}
	
int main()
{
	char data[] = "AAA.BBB";	
	f(data);
	return 0;
}


