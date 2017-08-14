#include <stdio.h>
int main()
{
	int i,j;
	for(i=0;i<8;i++)
	{	for(j=0;j<8;j++)
		{	
			if((i+1)%2!=0&&(j+1)%2==0) 
				printf("лл");
			else
			{	if((i+1)%2==0&&(j+1)%2!=0) 	printf("лл");
				else printf(" ");
		
			}
		}
		printf("\n");
	}
	return 0;
}