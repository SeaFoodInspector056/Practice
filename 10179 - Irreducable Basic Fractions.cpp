#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n)
    {
        int ans = n;
        int temp = n;
        for (long long i = 2; i * i <= temp; i++)
            if (temp % i == 0)
            {
                ans -= ans / i;//an = ans * (1 - 1/i) 因為i為ans的質因數 所以ans/i為整數
                while (temp % i == 0) temp /= i;//把temp的那個質因數的倍數都刪去
            }

        if (temp > 1) ans -= ans / temp;//剩餘的質因數(有可能會有最多一個質因數大於根號)

        cout << ans << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10179 - Irreducable Basic Fractions.cpp" -o test.exe; Get-Content in.txt | .\test.exe