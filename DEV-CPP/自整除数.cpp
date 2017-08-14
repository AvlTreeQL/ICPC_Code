#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=1,a=0,b,c,d,e=0;
	scanf("%d",&n);
	while(n/i!=0)
	{
		i=i*10;
		a=a+1;
	}
	c=a;
	while(c!=0)
	{
		b=pow(10,c);
		d=pow(10,c-1);
		c=c-1;
		e=e+n%b/d;
	}
	if(n%e==0) printf("TRUE\n");
	else printf("FALSE\n");

	return 0;
}
/*【问题描述】对一个整数n(n<10000),如果其各个位数的数字相加得到的数m能整除n,则称n为自整除数。
                        例如21，21%(2+1)==0， 所以21是自整除数。
【输入形式】一个整数n。
【输出形式】若n为自整除数，则输出TRUE,否则输出FALSE。
【样例输入】42
【样例输出】TRUE
【样例说明】说明42是自整除数。 */