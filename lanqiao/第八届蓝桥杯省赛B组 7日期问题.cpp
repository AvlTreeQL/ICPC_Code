/*
���⣺��������

С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
�����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��  

����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�  

����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��

����
----
һ�����ڣ���ʽ��"AA/BB/CC"��  (0 <= A, B, C <= 9)  

���
----
������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�  

59/12/31 
��������
----
02/03/04  

�������
----
2002-03-04  
2004-02-03  
2004-03-02  

��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

ע�⣺
main������Ҫ����0;
ֻʹ��ANSI C/ANSI C++ ��׼;
��Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
���������ĺ���������ȷ����Դ�ļ��� #include <xxx>
����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύ����ʱ��ע��ѡ�����������������ͺͱ��������͡�

*/

#include<iostream>
#include<string>
#include<cstring>
#include<set> 
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip> 
#include<cstdio>
using namespace std;
class node
{
public:
	int y;
	int m;
	int d;
	node(int a,int b,int c)
	{
		y=a;
		m=b;
		d=c;
	}
	bool operator <(const node &b) const
	{
		if(y==b.y)
		{
			if(m==b.m)
				return d<b.d;
			else
				return m<b.m;
		}
		else 
			return y<b.y;
	}
};
set<node> v;
set<node>::iterator it;
void fun(int y,int m,int d)
{
	if(y<60) y+=2000;
	else y+=1900;
	int mm[13];
	mm[1]=mm[3]=mm[5]=mm[7]=mm[8]=mm[10]=mm[12]=31;
	mm[4]=mm[6]=mm[9]=mm[11]=30;
	if(y%4==0&&y%100!=0||y%400==0)
		mm[2]=29;
	else mm[2]=28;
	if(m<=12&&m>=0&&d<=mm[m]&&d>=0)
		v.insert(node(y,m,d));
}
int main()
{
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	fun(a,b,c); //�в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
	fun(c,a,b);
	fun(c,b,a);

	for(it=v.begin();it!=v.end();it++)
	{
		printf("%d-%02d-%02d\n",it->y,it->m,it->d);
	}
	return 0;
}   

