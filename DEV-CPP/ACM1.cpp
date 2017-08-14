#include<stdio.h>
int main()
{
    __int64 n,a,b,c;
	__int64 min(__int64 a,__int64 b);
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if(n%4==0)
        printf("0\n");
    else if(n%4==1)
        printf("%I64d\n",min(a*3,min(a+b,c)));
    else if(n%4==2)
        printf("%I64d\n",min(a*2,min(b,c*2)));
    else if(n%4==3)
        printf("%I64d\n",min(a,min(b+c,c*3)));
    return 0;
}
__int64 min(__int64 a,__int64 b)
{
	if(a>b) return b;
	else return a;
}