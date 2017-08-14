#include <stdio.h>
 
int letter,digit,space,others;
int main()
{
     char str1[100];
     void tongji(char str0[]);
     gets(str1);
     letter=0;
     digit=0;
     space=0;
     others=0;
     tongji(str1);
     printf("%d %d %d %d\n",letter,digit,space,others);
     return 1;
}
 
void tongji(char str0[])
{
     int i;
     for(i=0;str0[i]!='\0';i++)
     {
         if(str0[i]>='a'&&str0[i]<='z'||str0[i]>='A'&&str0[i]<='z')
              letter++;
         else if(str0[i]>='0'&& str0[i]<='9')
              digit++;
         else if(str0[i]==' ')
              space++;
         else others++;
     }
}