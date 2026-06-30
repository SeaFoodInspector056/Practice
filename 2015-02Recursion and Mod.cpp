#include <bits/stdc++.h>
using namespace std;
using ull = long long;

ull big_mod(int n)
{
    ull result = 1;
    ull b = 3, p = n;
    int m = 1000000001;

    while (p > 0)
    {
        if (p & 1)
            result = result * b % m;
        b = b * b % m;
        p >>= 1;  
    }
    
    return (result - 2 + m) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n)
        cout << big_mod(n) << '\n';

    return 0;
}
// g++ -std=c++11 ".\2015-02Recursion and Mod" -o test.exe; Get-Content in.txt | .\test.exe