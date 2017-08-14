#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
	void code(char *s);
    scanf("%s", s);//处理密码
    code(s);
    return 0;
}
void code(char *s)
{
    int i = 0, n = 0, ti, tj;
    int j = strlen(s) - 1;

    while (i <= j)
    {
        //第一种情况  如果前后相等，则像中间靠拢
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        //如果不相等  则又分两种情况
        else
        {
            ti = i;
            tj = j;
            //以右边为标记  左边为游标  寻找相等的情况
            while (s[ti] != s[j] && ti < j)
            {
                ti++;
            }
            //以左边为标记  右边为游标  寻找相等的情况
            while (s[i] != s[tj] && i <= tj)
            {
                tj--;
            }
            //比较这个游标移动的距离，取小的距离
            if ((ti - i) < (j - tj))
            {
                n += ti - i;
                i = ti;     //将i置为新的起点
            }
            else
            {
                n += j - tj;
                j = tj;     //将j置为新的终点
            }
        }
    }
    printf("%d\n", n);
}
