#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll big_mod(int b, int p, int m)
{
    if (m == 1) return 0;
    ll result = 1;
    b %= m;
    while (p > 0)
    {
        if (p & 1)//當p的最後一個bit是1才把b乘進result
            result = result * b % m;//每個都%m來最小化
        b = b * b % m;//b^1 -> b^2 -> b^4...
        p >>= 1;//把最後第二個移到最後一個
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, p, m;
    while (cin >> b >> p >> m)
        cout << big_mod(b, p, m) << '\n';

    return 0;
}
//g++ -std=c++11 ".\374 - Big Mod.cpp" -o test.exe; Get-Content in.txt | .\test.exe