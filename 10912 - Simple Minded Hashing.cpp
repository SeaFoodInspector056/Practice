#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[27][27][352] = {0};//已排到的前面字母 長度 總和 : 可能性
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= 26; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= 351; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];//不選字母
                if (j >= 1 && k >= i) dp[i][j][k] += dp[i - 1][j - 1][k - i];//選字母
            }

    int T = 1;
    int L, S;
    while (cin >> L >> S)
    {
        if (!L && !S) break;
        
        cout << "Case " << T++ << ": " << ((L <= 26 && S <= 351) ? dp[26][L][S] : 0) << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10912 - Simple Minded Hashing.cpp" -o test.exe; Get-Content in.txt | .\test.exe