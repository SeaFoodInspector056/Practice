#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    while(getline(cin,s1) && getline(cin,s2))
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));//用vector比較safe

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (s1[i - 1] == s2[j - 1])//s1, s2的index跟dp不一樣!!!
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        cout << dp[n1][n2] << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10405 - Longest Common Subsequence.cpp" -o test.exe; Get-Content in.txt | .\test.exe