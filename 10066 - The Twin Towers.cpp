#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1, n2, t = 0;
    while (cin >> n1 >> n2 && (n1 != 0 && n1 != 0))
    {
        t++;
        vector<int> r1(n1 + 1), r2(n2 + 1);
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < n1; i++)
            cin >> r1[i];
        for (int i = 0; i < n2; i++)
            cin >> r2[i];
        
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (r1[i - 1] == r2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        cout << "Twin Towers #" << t << '\n';
        cout << "Number of Tiles : " << dp[n1][n2] << '\n';
        cout << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10066 - The Twin Towers.cpp" -o test.exe; Get-Content in.txt | .\test.exe