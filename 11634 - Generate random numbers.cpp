#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a0;
    while (cin >> a0 && a0)
    {
        vector<bool> visited(10000, false);
        visited[a0] = true;

        int ans = 1;

        while (true)
        {
            int ai = a0 * a0 / 100 % 10000;
            if (visited[ai]) break;
            ans++;
            visited[ai] = true;
            a0 = ai;
        }

        cout << ans << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\11634 - Generate random numbers.cpp" -o test.exe; Get-Content in.txt | .\test.exe