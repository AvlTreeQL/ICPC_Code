/*

���⣺����������

���һЩ�߳�������ͬ�������Σ�����ǡ��ƴ��һ������������Σ������Ϊ���������Ρ�

��ʷ�ϣ����ǻ��˺ܾò��ҵ����������������Ρ����磺���±߳���22��������
2 3 4 6 7 8 12 13 14 15 16 17 18 21 22 23 24 26 27 28 50 60
�硾ͼ1.png��������ϣ�����һ�ֽⷨ����ʱ��
�����ϱ��ص��ǣ�60 50
�����±��ص��ǣ�26 28 17 21 18

22������������һ����8�֡�������������һ�֣�
2 5 9 11 16 17 19 21 22 24 26 30 31 33 35 36 41 46 47 50 52 61
���������÷����������ϱ��ص��Ǵ���������Ϊ��47 46 61��
���ܼ�����������±��ص����ļ�����������

���ύ�������±��ص������εı߳��������ң��ÿո�ֿ���

��Ҫ��д�κζ�������ݻ�˵�����֡�

*/
#include <iostream>
using namespace std;

// ȫ�ֱ���
namespace Global
{
const int MaxS = 46+47+61;	// �����εı߳�
int All[] = {2,5,9,11,16,17,19,21,22,
             24,26,30,31,33,35,36,41,50,52
            };// ��ѡ�����α߳�
int Length = sizeof(All)/sizeof(All[0]);// ��ѡ�����ε�����
int Square[MaxS][MaxS]= {0};	// ��ʾ���������������
}
// �߶������
struct TNode
{
    int L, R;			// [L, R]
    int height;			// �θ߶�( -1ʱ��ʾ�öβ�ƽ��,�߶������� )
    int inc;			// �߶�����
    // ������
    inline int Width()const
    {
        return R-L+1;
    }
    // �����е�
    inline int Mid()const
    {
        return (L+R)>>1;
    }
} NSet[1024];

inline int LSon( int i )
{
    return i<<1;
}
inline int RSon( int i )
{
    return LSon(i)+1;
}
inline int Parent( int i)
{
    return i>>1;
}

// �����߶���
void BuildTree( int i, int L, int R )
{
    TNode* p = NSet+i;
    p->L = L;
    p->R = R;
    p->height = 0;
    p->inc = 0;

    if( L < R )
    {
        int m = p->Mid();
        BuildTree( LSon(i), L, m );
        BuildTree( RSon(i), m+1, R);
    }
}
// ���������´��ݵ���
// ע: NSet[i]����Ϊƽ������
inline void Adjust( int i )
{
    if( NSet[i].inc != 0 )
    {
        NSet[i].height += NSet[i].inc;
        if( NSet[i].L != NSet[i].R )
        {
            NSet[LSon(i)].inc += NSet[i].inc;
            NSet[RSon(i)].inc += NSet[i].inc;
        }
        NSet[i].inc = 0;
    }
}

// ������[L,R]�ĸ߶�ͳһ����(�����)inc
// ע: ���� [L, R] ����ƽ��
void Add(int i, int L, int R, int inc )
{
    TNode* p = NSet+i;
    if( p->L == L && p->R == R )
    {
        // ������ƽ���Բ���
        p->inc += inc;
        Adjust(i);
    }
    else
    {
        int m = p->Mid();

        if( p->height != -1 ) // ��ʾ�öα���ƽ����
        {
            Adjust(i);
            p->height = -1;	  // ���ڿ�ʼ�öβ���ƽ��
        }

        int ls = LSon(i), rs = RSon(i);
        if( R <= m )
            Add( ls, L, R, inc );
        else if( L > m )
            Add( rs, L, R, inc );
        else
        {
            Add( ls, L, m, inc );
            Add( rs, m+1, R, inc );
        }

        // ƽ���Իָ�����
        if(NSet[ls].height != -1)
        {
            Adjust(ls);
            if(NSet[rs].height != -1)
            {
                Adjust(rs);
                if(NSet[ls].height == NSet[rs].height)
                    p->height = NSet[ls].height;
            }
        }
    } // end else
}
// ��ȡ��Ͷ�����
void GetLowestInterval(int i, TNode* prev, TNode* lowest )
{
    TNode* p = NSet+i;
    if( p->height == -1 )
    {
        GetLowestInterval( LSon(i), prev, lowest );
        GetLowestInterval( RSon(i), prev, lowest );
    }
    else
    {
        prev->R = p->R;
        // ����ȸ�����������
        if( p->height != prev->height )
        {
            prev->L = p->L;
            prev->height = p->height;
        }

        // �����������
        if( prev->height <= lowest->height )
        {
            lowest->height = prev->height;
            lowest->L = prev->L;
            lowest->R = prev->R;
        }
    }
}
bool Dfs( int L, int R ,int H )
{
    if( L > R )
    {
        TNode p, m;
        m.height = 1000;
        m.L = m.R = 1000;
        p.height = 1000;
        p.L = p.R = -1;

        GetLowestInterval(1, &p, &m);
        L = m.L;
        R = m.R;
        H = m.height;
    }

    int Width = R-L+1, temp=0;
    if( Width == Global::MaxS && H != 0 ) return true;

    for( int i = Global::Length; i-- > 0 ;)
    {
        temp = Global::All[i];
        if( temp != 0 && temp <= Width )
        {
            Global::All[i] = 0;
            Add( 1, L, L+temp-1, temp);
            Global::Square[ H+temp-1 ][ L ] = temp;
            if( Dfs( L+temp, R, H ) == true ) return true;
            Add( 1, L, L+temp-1, -temp);
            Global::All[i] = temp;
        }
    }
    return false;
}
int main(int argc, char** argv)
{
    BuildTree( 1, 0, Global::MaxS-1 );

    Add( 1, 0, 46, 47);
    Add( 1, 47, 92, 46);
    Add( 1, 93, 153, 61);

    if( Dfs( 1, 0, 0 ) )
    {
        for( int i = 0,t=0; i < Global::MaxS; i+=t)
        {
            t = Global::Square[ Global::MaxS-1 ][i];
            cout << t << ' ';
        }
    }
    return 0;
}

