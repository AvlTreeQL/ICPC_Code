/*
��һ����ֵĹ��ң�����Ĺ�����������̬����Զֻ�����档������������һ������һ�������ʱ�򡪡���������ͬ�۵��������һ�����������鶼������ͬ��һ������ͬ�۵��������һ���ֲ���ͬ�۵���˵�ʱ�����˶��᲻�ټ�����ͬ�������ֲ���ͬ�۵��������һ�����ۺ󷴶����������鿪ʼ��ͬ��

�����ʽ

����������У�ÿ�а��� N(1��N��50) �����֣��ֱ��ʾ�����˶��� NN �������Ӧ�Ŀ�����0 ��ʾ����ͬ��1 ��ʾ��ͬ��

�����ʽ

�������һ�У����� NN �����֣���ʾ���������󣬶����� NN ����������տ�����

��������

11100101
00101011
�������

00110001
*/
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#include<bitset>
using namespace std;
int main() {
//	freopen("intput.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	string aa, bb;
	cin >> aa >> bb;
	bitset<50> a(aa), b(bb);
	cout <<(~(a^b)).to_string().substr(50-aa.length(),aa.length()) << endl;
	return 0;
}
