#include <stdio.h>
int main()
{
	int m,n,i,a;
	scanf("%d%d",&m,&n);
	for(i=1;i<m||i<n;i++)
		if(m%i==0&&n%i==0) a=i;
	printf("%d %d",a,m*n/a);

	return 0;
}
//�������ĳ˻��������ǵ����Լ������С������