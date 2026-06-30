#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> dp(n + 1);
        
        int temp = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int bet;
            cin >> bet;
            temp = max(bet, temp + bet);
            ans = max(ans, temp);
        }

        if (ans)
            cout << "The maximum winning streak is " << ans;
        else    
            cout << "Losing streak";

        cout << ".\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
//g++ -std=c++11 ".\10684 - The jackpot.cpp" -o test.exe; Get-Content in.txt | .\test.exe