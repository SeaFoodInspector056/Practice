#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0)
                sum += i;

        if (sum == n)
            cout << "perfect\n";
        else if (sum > n)
            cout << "abundant\n";
        else 
            cout << "deficient\n";
    }

    return 0;
}
//g++ -std=c++11 ".\382 - Perfection.cpp" -o test.exe; Get-Content in.txt | .\test.exe