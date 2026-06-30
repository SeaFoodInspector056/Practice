#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> mp;

    while (n--)
    {
        string s;
        cin >> s;
        mp[s]++;
        getline(cin,s);
    }

    for (auto i : mp)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}
