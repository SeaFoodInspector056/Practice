#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        vector<vector<bool>> pld(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            pld[i][i] = true;

        for (int len = 2; len <= n; len++)
            for (int l = 0; l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                if (s[l] == s[r])
                {
                    if (len == 2)
                        pld[l][r] = true;
                    else
                        pld[l][r] = pld[l + 1][r - 1];
                }
                else 
                    pld[l][r] = false;
            }

        vector<int> dp(n + 1, INT_MAX);//已分割幾個子字串
        dp[0] = 0;

        for (int i = 1; i <= n; i++) //在pld是索引值+1 在dp是前j個字元有幾個分割
            for (int j = 0; j < i; j++) //在pld是索引值 在dp是前j個字元有幾個分割
                if (pld[j][i - 1] and dp[j] != INT_MAX) //若可形成迴文
                    dp[i] = min(dp[i], dp[j] + 1);

        cout << dp[n] << '\n';
    }

    return 0;
}