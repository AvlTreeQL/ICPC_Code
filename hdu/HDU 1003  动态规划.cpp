/*
Problem Description
Given a sequence a[1],a[2],a[3]......a[n], 
your job is to calculate the max sum of a sub-sequence. 
For example, given (6,-1,5,4,-7), 
the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. 
Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. 
The first line is "Case #:", # means the number of the test case. 
The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. 
If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6

3
5 -5 -4 -3 -2 -10
5 6 -7 4 -7 6
7 0 6 -1 1 -6 7 -5
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int ii=0;ii<n;ii++)
	{
		int num,max,p1,p2,temp;
		vector<int> sum,a;
		cin>>num;
		a.resize(num);
		sum.resize(num);
		cin>>a[0];
		max=sum[0]=a[0];
		p1=p2=0;
		temp=0;
		int before=max;
		for(int i=1;i<num;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];			
			if(before<0)
			{
				temp=i;
			}
			before=sum[i]-sum[temp]+a[temp];
			if(before>max)
			{
				max=before;
				p1=temp;
				p2=i;
			}	
		}
		cout<<"Case "<<ii+1<<":"<<endl<<max<<' '<<p1+1<<' '<<p2+1<<endl;
		if(ii+1!=n)cout<<endl; 
	}
	return 0;
}
