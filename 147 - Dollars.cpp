#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    long long dp[30001] = {0};
    dp[0] = 1;

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 30001; j++)//順序很重要!!!!!!!!!!
        {
            if (j + coin[i] >= 30001)
                break;

            dp[j + coin[i]] += dp[j];
        }

    string s;
    while (cin >> s)
    {
        if (s == "0.00")
            break;

        long long sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]) == false)
                continue;
            sum = sum * 10 + (s[i] - '0');
        }

        cout << setw(6) << s << setw(17) << dp[sum] << '\n';
    }

    return 0;
}
