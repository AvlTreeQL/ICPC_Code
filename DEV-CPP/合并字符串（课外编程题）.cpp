/*
【问题描述】
编写一个函数char * str_bin(char* str1, char* str2)， str1、str2是两个有序字符串（其中字符按ASCII码从小到大排序），将str2合并到字符串str1中，要求合并后的字符串仍是有序的，允许字符重复。在main函数中测试该函数：从键盘输入两个有序字符串，然后调用该函数，最后输出合并后的结果。
【输入形式】
分行从键盘输入两个有序字符串（不超过100个字符）
【输出形式】
输出合并后的有序字符串
【输入样例】
aceg
bdfh
【输出样例】
abcdefgh
【样例说明】
输入两个有序字符串aceg和bdfh，输出合并后的有序字符串abcdefgh
【评分标准】
结果完全正确得20分，每个测试点4分，提交程序文件名为combine.c。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	return *(char *)a>*(char *)b?1:-1;
}
char * str_bin(char* str1, char* str2)
{
	strcat(str1,str2);
	qsort(str1,(int)strlen(str1),sizeof(char),cmp);
	return str1;
}
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	puts(str_bin(a,b));
	return 1;
}
