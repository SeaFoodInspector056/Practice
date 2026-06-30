#include <bits/stdc++.h>
using namespace std;

string solve()
{
    string line;
    getline(cin, line);

    istringstream ss(line);
    string weight;
    vector<int> lug;
    int sum = 0;
    while (ss >> weight)
    {
        int num = stoi(weight);
        lug.push_back(num);
        sum += num;
    }

    if (sum % 2 != 0) return "NO";

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int w : lug)
        for (int j = target; j >= w; j--)//由大到小確保非重複使用
            if (dp[j - w]) 
                dp[j] = true;

    return dp[target] ? "YES" : "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    cin.ignore();
    while (m--)
        cout << solve() << '\n';    

    return 0;
}
//++ -std=c++11 ".\10664 - Luggage.cpp" -o test.exe; Get-Content in.txt | .\test.exe   