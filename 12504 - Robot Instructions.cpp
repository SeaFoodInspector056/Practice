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
        int n;
        cin >> n;
        cin.ignore();

        int pt = 0;
        vector<int> dp(n);
        for (int i = 0 ; i < n; i++)
        {
            string s;
            getline(cin, s);

            if (s == "LEFT")
                dp[i] = -1;
            else if (s == "RIGHT")
                dp[i] = 1;
            else
            {
                int temp = 0;
                for (int j = 8; j < s.size(); j++)
                    temp = temp * 10 + static_cast<int>(s[j] - '0');

                dp[i] = dp[temp - 1];
            }

            pt += dp[i];
        }

        cout << pt << endl;
    }

    return 0;
}
//g++ -std=c++11 ".\12504 - Robot Instructions.cpp" -o test.exe; Get-Content in.txt | .\test.exe