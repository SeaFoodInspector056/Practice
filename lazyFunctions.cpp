#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

//建質數表
vector<int> primeList(1, 2);
void build_primeList()
{
    for (int i = 3; i < 10000; i += 2)//上限看題目
    {
        bool isPrime = true;
        for (int j = 0; primeList[j] * primeList[j] <= i; j++)
            if (i % primeList[j] == 0)
            {
                isPrime = false;
                break;
            }
        if (isPrime)
            primeList.push_back(i);
    }
}

ull big_mod(int b, int p, int m)
{
    ull result = 1;
    b %= m;
    while (p > 0)
    {
        if (p & 1)
            result = result * b % m;
        b = b * b % m;
        p >>= 1;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}