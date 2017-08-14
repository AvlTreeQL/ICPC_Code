#include <stdio.h>
#include <string.h>
struct stu
{
	char name[10];
	int num;
	int age;
	char addr[15];
}a[100];
int n;
void display();
void save();
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%s",a[i].name,&a[i].num,&a[i].age,a[i].addr);
	}
	save();
	display();
	return 0;
}
void save()
{
	FILE *p;
	p=fopen("text","wb");
	int i;
	for(i=0;i<n;i++)
		fwrite(&a[i],sizeof(struct stu),1,p);
	fclose(p);
}
void display()
{
	FILE *p;
	struct stu b[100];
	int i;
	p=fopen("text","rb");
	for(i=0;i<n;i++)
		fread(&b[i],sizeof(struct stu),1,p);
	for(i=0;i<n;i++)
	{
		printf("%s %d %d %s\n",b[i].name,b[i].num,b[i].age,b[i].addr);
	}
}