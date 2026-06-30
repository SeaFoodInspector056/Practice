#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int>(c));
    for (auto &y : arr)
        for (auto &x : y)
            cin >> x;
    
    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[0][0] = arr[0][0];

    for (int i = 1; i < r; i++)
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    
    for (int i = 1; i < c; i++)
        dp[0][i] = dp[0][i - 1] + arr[0][i];
        
    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            dp[i][j] = min(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
    
    return dp[r - 1][c - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
        cout << solve() << '\n';

    return 0;
}
//g++ -std=c++11 ".\2015-07Minimum Path Sum.cpp" -o test.exe; Get-Content in.txt | .\test.exe