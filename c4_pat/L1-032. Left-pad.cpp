#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int n;
  char c;
  cin>>n>>c;
  cin.get();
  getline(cin,s);
  if(n>s.size())
  {
    for(int i=0;i<n-s.size();i++)
    {
      cout<<c;
    }
    cout<<s;
  }
  else cout<<s.substr(s.size()-n,n);
  return 0;
}
/*
��������΢���ϵ���Ϣ����һλ�����߲���NPM��Node Package Manager�����������ջ����Լ��Ŀ�Դ���룬���а���һ����left-pad��ģ�飬�������ģ���javascript�����React/Babel��̱���ˡ����Ǹ�ʲô����ģ�飿�������ַ���ǰ���һЩ������һ���ĳ��ȡ������á�*��ȥ����ַ�����GPLT����ʹ֮����Ϊ10������left-pad�Ľ����Ӧ���ǡ�******GPLT����Node����������left-pad����������һ��������������²ۡ������������ʵ��һ�����ģ�顣

�����ʽ��

�����ڵ�һ�и���һ��������N��<=104����һ���ַ����ֱ���������ַ����ĳ��Ⱥ����������ַ����м���1���ո�ֿ����ڶ��и���ԭʼ�ķǿ��ַ������Իس�������

�����ʽ��

��һ�����������ַ�����

��������1��
15 _
I love GPLT
�������1��
____I love GPLT
��������2��
4 *
this is a sample for cut
�������2��
 cut

*/
