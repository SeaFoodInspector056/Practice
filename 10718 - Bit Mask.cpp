#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long N, L, U;
    while (cin >> N >> L >> U)
    {
        bitset<32> n(N), m(0);
        for (int i = 31; i >= 0; i--)
        {
            m[i] = 1;//先設定成1來方便求N OR M的最大值
            if ((n[i] and m.to_ullong() > L) or m.to_ullong() > U)
                m[i] = 0;
        }

        cout << m.to_ullong() << '\n';
    }

    return 0;
}

int main_2()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long N, L, U;
    while (cin >> N >> L >> U)
    {
        int M = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (M | (1 << i) > U) //M加上第i位必定為1
                continue;
            
            if (M | (1 << i) <= L or !(N & (1 << i))) //M小於L 或是 N在i位時不是1
                M |= (1 << i); // M = M | (1 << i)
        }

        cout << M << '\n';
    }

    return 0;
}

//M     = 0000 1010  (10)
//1<<3  = 0000 1000  (8)
//
//M | (1<<3) = 0000 1010
//           | 0000 1000
//           = 0000 1010  (10)  ← 沒變，因為那個bit本來就是1
//
//M     = 0000 0010  (2)
//1<<3  = 0000 1000  (8)
//
//M | (1<<3) = 0000 0010
//           | 0000 1000
//           = 0000 1010  (10)  ← 把第3位強制設成1