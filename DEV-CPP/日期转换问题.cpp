/*【问题描述】在我们现在使用的日历中, 闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年。例如：1700, 1800, 1900 和 2100 不是闰年，而 1600, 2000和2400是闰年。 给定从公元2000年1月1日开始逝去的天数（2000.1.1. 是星期六），你的任务是给出这一天是哪年哪月哪日星期几。
【输入形式】输入包含若干行，每行包含一个正整数，表示从2000年1月1日开始逝去的天数。输入最后一行是?1, 不必处理。可以假设结果的年份不会超过9999。
【输出形式】对每个测试样例，输出一行，该行包含对应的日期和星期几。格式为“YYYY-MM-DD Day OfWeek”, 其中 “DayOfWeek” 必须是下面中的一个： "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" 或 "Saturday“。
【样例输入】1730 
                          1740 
                          1750
                          1751 
                          -1 
【样例输出】2004-09-26 Sunday 
                       2004-10-06 Wednesday 
                       2004-10-16 Saturday 
                       2004-10-17 Sunday*/
#include<stdio.h>
int main()
{
	char a[8][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int n;
	int year=2000;
	int m=1,s=6;
	scanf("%d",&n);
	while(n!=-1)
	{
	while(n/365!=0)
	{
		n=n-365;
		s=s+365;
		if((year%400==0)||((year%4==0)&&(year%100!=0)))
		{
			n=n-1;
			s=s+1;
			if(n==-1)
			{
				s=s%7;
				n=365;
				break;
			}
		}
		s=s%7;
		year++;
	}
	while(n-b[m]>=0)
	{
		n=n-b[m];
		s=s+b[m];
		if((m==2)&&((year%400==0)||((year%4==0)&&(year%100!=0))))
		{
			n=n-1;
			s=s+1;
			if(n==-1)
			{
				s=s-29;
				n=28;
				break;
			}
		}
		s=s%7;
		m++;
	}
	s=(s+n)%7;
	printf("%d-%02d-%02d %s\n",year,m,n+1,a[s]);
	scanf("%d",&n);
	year=2000;m=1;s=6;
	}
	return 0;
}