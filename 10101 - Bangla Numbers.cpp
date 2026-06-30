#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t = 1;
vector<string> name = {"kuti", "lakh", "hajar", "shata"};
map<string, int> mp 
{
    {name[0], 10000000},
    {name[1], 100000}, 
    {name[2], 1000},
    {name[3], 100}
};

void find_digit(int n, bool last)
{
    for (int i = 0; i < 4; i++)
    {
        int ans = n / mp[name[i]];
        if (ans > 0) cout << ' ' << ans << ' ' << name[i];
    
        n %= mp[name[i]];
    }

    if (n > 0) cout << ' ' << n;

    if (last) cout << ' ' << name[0];
    else cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    while (cin >> n)
    {
        cout << setw(4) << t++ << '.';

        if (n == 0) cout << ' ' << 0 << '\n';
        else
        {
            if (n > mp[name[0]])
            {
                int temp = n / mp[name[0]];
                find_digit(temp, true);

                n %= mp[name[0]];
            }

            find_digit(n, false);
        }
    }

    return 0;
}