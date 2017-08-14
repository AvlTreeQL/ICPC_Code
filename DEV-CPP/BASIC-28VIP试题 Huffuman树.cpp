 #include<stdio.h>
 #include<stdlib.h>
 int cmp(const void*a,const void*b)
 {
 	return *(int *)a<*(int *)b?1:-1;
 }
 int main()
 {
 	int n,i,*a;
 	long sum=0;
 	scanf("%d",&n);
 	a=(int *)malloc(sizeof(int)*n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	while(n!=1)
 	{
 		qsort(a,n,sizeof(int),cmp);
 		a[n-2]+=a[n-1];
 		sum+=a[n-2];
		a[n-1]='\0';
 		n--;
 	}
 	printf("%ld",sum);
 	return 0;
 }
