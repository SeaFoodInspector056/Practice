#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(46);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 45; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n] << '\n';

    return 0;
}
//g++ -std=c++11 ".\2015-08Climbing Stairs.cpp" -o test.exe; Get-Content in.txt | .\test.exe