#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<pair<string, int>> mp;
    while (m--)
    {
        string s;
        int num;
        cin >> s >> num;
        mp.push_back({s, num});
    }

    while (n--)
    {
        int salary = 0;

        string s;
        while (cin >> s && s != ".")
            for (int i = 0; i < mp.size(); i++)
                if (mp[i].first == s)
                {
                    salary += mp[i].second;
                    break;
                }

        cout << salary << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10295 - Hay Points.cpp" -o test.exe; Get-Content in.txt | .\test.exe 