#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
	void code(char *s);
    scanf("%s", s);//��������
    code(s);
    return 0;
}
void code(char *s)
{
    int i = 0, n = 0, ti, tj;
    int j = strlen(s) - 1;

    while (i <= j)
    {
        //��һ�����  ���ǰ����ȣ������м俿£
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        //��������  ���ַ��������
        else
        {
            ti = i;
            tj = j;
            //���ұ�Ϊ���  ���Ϊ�α�  Ѱ����ȵ����
            while (s[ti] != s[j] && ti < j)
            {
                ti++;
            }
            //�����Ϊ���  �ұ�Ϊ�α�  Ѱ����ȵ����
            while (s[i] != s[tj] && i <= tj)
            {
                tj--;
            }
            //�Ƚ�����α��ƶ��ľ��룬ȡС�ľ���
            if ((ti - i) < (j - tj))
            {
                n += ti - i;
                i = ti;     //��i��Ϊ�µ����
            }
            else
            {
                n += j - tj;
                j = tj;     //��j��Ϊ�µ��յ�
            }
        }
    }
    printf("%d\n", n);
}
