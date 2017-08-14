/*【问题描述】N只小白鼠(1 < N < 100)，每只鼠头上戴着一顶有颜色的帽子并且有一个编号。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们的编号和头上帽子的颜色。编号是长度为5的字符串，如：“W-101”,“T-002”等，帽子的颜色用“red”,“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
【输入形式】输入数据在文本文件IN.TXT中，数据格式是：第一行为一个整数N，表示小白鼠的数目。接下来的N行，每行是一只白鼠的信息。第一个为编号；第二个为不大于100的正整数，表示白鼠的重量；第三个为表示白鼠的帽子颜色的字符串，其长度不超过10个字符。
【输出形式】按照白鼠重量的从大到小顺序输出白鼠的编号和帽子颜色到文本文件OUT.TXT中。
【样例输入】IN.TXT文件
                   3
                   T-001 30 red
                   W-001 50 blue
                   T-101 40 green                      
【样例输出】OUT.TXT文件
                   W-001 blue
                   T-101 green
                   T-001 red   */
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *p;
	struct mouse
	{
		char name[6];
		int wight;
		char color[10];
	}mou[101],t;
	int n,i,j;
	scanf("%d",&n);
	if((p=fopen("IN.TXT","w"))==NULL)
	{printf("cannot open this file1\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		scanf("%s%d%s",t.name,&t.wight,t.color);
		fprintf(p,"%s %d %s\n",t.name,t.wight,t.color);
	}
	fclose(p);
	if((p=fopen("IN.TXT","r"))==NULL)
	{printf("cannot open this file2\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fscanf(p,"%s%d%s",mou[i].name,&mou[i].wight,mou[i].color);
		//printf("%s %d %s\n",mou[i].name,mou[i].wight,mou[i].color);
	}
	fclose(p);
	for(i=1;i<n;i++)
		for(j=1;j<=n-i;j++)
			if(mou[j].wight<mou[j+1].wight)
			{
				t=mou[j];
				mou[j]=mou[j+1];
				mou[j+1]=t;
			}
	if((p=fopen("OUT.TXT","w"))==NULL)
	{printf("cannot open this file3\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fwrite(&mou[i],sizeof(struct mouse),1,p);
	}
	fclose(p);
	if((p=fopen("OUT.TXT","r"))==NULL)
	{printf("cannot open this file4\n");exit(0);}
	for(i=1;i<=n;i++)
	{
		fread(&t,sizeof(struct mouse),1,p);
		printf("%s %s\n",t.name,t.color);
	}
	fclose(p);
	return 0;
}