#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "PERFECTION OUTPUT\n";

    int n;
    while (cin >> n && n != 0)
    {
        int sum = 0;
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0)
                sum += i;

        cout << setw(5) << n;
        if (sum == n)
            cout << "  PERFECT\n";
        else if (sum > n)
            cout << "  ABUNDANT\n";
        else 
            cout << "  DEFICIENT\n";
    }

    cout << "END OF OUTPUT\n";//加\n比較保險

    return 0;
}
//g++ -std=c++11 ".\382 - Perfection.cpp" -o test.exe; Get-Content in.txt | .\test.exe