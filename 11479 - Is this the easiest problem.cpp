#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll len[3];
        cin >> len[0] >> len[1] >> len[2];

        sort(len, len + 3);
        
        ll a = len[0];
        ll b = len[1];
        ll c = len[2];

        cout << "Case " << i << ": ";
        if (len[0] < 0 || a + b <= c || c - b >= a)
            cout << "Invalid";
        else if (a == b && b == c)
            cout << "Equilateral";
        else if (a == b || b == c)
            cout << "Isosceles";
        else 
            cout << "Scalene";
        cout << '\n';
    }

    return 0;
}
// g++ -std=c++11 "11479 - Is this the easiest problem.cpp" -o test.exe; Get-Content in.txt | .\test.exe