#include <bits/stdc++.h>
using namespace std;

void gay(string &s)
{
    auto foundn = s.find('\n');
        while (foundn != string::npos)
        {
            s.erase(s.find('\n'));
            auto foundn = s.find('\n');
        }

        auto foundr = s.find('\r');
        while (foundr != string::npos)
        {
            s.erase(s.find('\r'));
            auto foundr = s.find('\r');
        }
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second != b.second ? a.second < b.second : a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int cnt = 0;
    while (getline(cin, s))
    {

        map<int, int> mp;
        for (char &x : s)
            mp[x]++;

        vector<pair<int, int>> mtov(mp.begin(), mp.end());
        sort(mtov.begin(), mtov.end(), cmp);

        if (cnt) cout << '\n';
        for (auto &x : mtov)
            cout << x.first << ' ' << x.second << '\n';

        cnt++;
    }

    return 0;
}
