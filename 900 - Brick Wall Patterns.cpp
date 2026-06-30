#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[51];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i < 51; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    int n;
    while (cin >> n and n != 0)
        cout << dp[n] << '\n';
    

    return 0;
}