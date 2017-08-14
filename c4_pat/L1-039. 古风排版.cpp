/*L1-039. 古风排版
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。
输入格式：
输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。
输出格式：
按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）
输入样例：
4
This is a test case
输出样例：
asa T
st ih
e tsi
 ce s
 */
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	int h,l,i,j,t=0;
 	string s;
	char s1[100][100];
 	cin>>h;
 	cin.get();
 	getline(cin,s);
 	l=s.size()/h;
	if(s.size()%h==0) 
	{
		l--;
	}
	else 
	{
		s.insert(s.size(),h-s.size()%h,' ');
	}
	
	for(i=l;i>=0;i--)
 	{
 		 for(j=0;j<h;j++)
 		 {
 			s1[j][i]=s[t++];
 //			cout<<s1[j][i]<<s[t-1]<<endl;
 		 }
 	}
 	for(i=0;i<h;i++)
 	{

 		cout<<s1[i]<<endl;
 	}
 	return 0;
 }
