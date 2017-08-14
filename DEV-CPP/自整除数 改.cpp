#include<stdio.h>
int main()
{
	int n,a,m=0;
	scanf("%d",&n);
	a=n;
	while(n!=0)
	{
		m=m+n%10;
		n=n/10;
	}
	if(a%m==0) printf("TRUE\n");
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