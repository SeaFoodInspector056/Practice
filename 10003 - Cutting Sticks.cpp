#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l;
    while (cin >> l && l)
    {
        int n;
        cin >> n;
        
        vector<int> p(n + 2);//多包含0, l 切點
        p[0] = 0;
        for (int i = 1; i < n + 1; i++)
            cin >> p[i];
        p[n + 1] = l;

        int sz = n + 2;
        vector<vector<int>> dp(sz, vector<int>(sz, 0));

        for (int len = 2; len < sz; len++)
            for (int l = 0; l + len < sz; l++)
            {   
                int r = l + len;

                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; i++)
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] + p[r] - p[l]);
            }

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }

    return 0;
}
//g++ -std=c++11 ".\10003 - Cutting Sticks.cpp" -o test.exe; Get-Content in.txt | .\test.exe