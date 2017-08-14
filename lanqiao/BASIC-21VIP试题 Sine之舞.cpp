#include <iostream>
#include <string>


using namespace std;
// ¡¡ An=sin(1¨Csin(2+sin(3¨Csin(4+...sin(n))...)
// ¡¡¡¡Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
int print_An (int start ,int number,int flag)
{
	if (start<=number)
	{
		cout <<"sin("<<number;
		if (start+1<=number)
		{
			if (flag==1)
			cout <<"-";
			else
			cout <<"+";
			print_An(start+1,number,flag*-1);
		}
		cout<<")";
//if (print_An(start++,number,flag*-1))
	}
	else
	{
		return 0;
	}
}
int print_Sn (int number,int i)
{ 
	if (number!=0)
	{
		if (number!=1)
		cout <<"(";
		print_Sn(number-1,i+1);
		if (number!=1)
		cout <<")";
		print_An(1,number,1);
		cout <<"+";
		cout <<i;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int number;
	cin>>number;
//print_An(1,number,1);
	cout <<"Sn=";
	print_Sn(number,1);
	cout <<endl;
	return 0;
}
