#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    while (cin >> k >> n)
    {
        vector<double> dp(k + 1, 1.0 / (k + 1));//最後一個字元時的可能性

        for (int i = 2; i <= n; i++)
        {
            vector<double> ndp(k + 1, 0.0);

            for (int j = 0; j <= k; j++)
            {
                if (j > 0) ndp[j] += dp[j - 1];
                ndp[j] += dp[j];
                if (j < k) ndp[j] += dp[j + 1];

                ndp[j] /= (k + 1);
            }

            dp = ndp;
        }

        double tot = 0;
        for (int j = 0; j <= k; j++)
            tot += dp[j];

        cout << fixed << setprecision(5) << tot * 100 << '\n';
    }

    return 0;
}