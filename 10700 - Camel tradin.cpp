#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    int sSize = s.size();

    istringstream ss(s);
    char op;
    ll n;
    ss >> n;

    vector<ll> maxTemp{n};
    vector<ll> minTemp{n};

    while (ss >> op >> n)
    {
        if (op == '+')
        {
            maxTemp[maxTemp.size() - 1] += n;
            minTemp.push_back(n);
        }
        else if (op == '*')
        {
            minTemp[minTemp.size() - 1] *= n;
            maxTemp.push_back(n);
        }
    }

    ll maxVal = 1;
    for (ll x : maxTemp)
        maxVal *= x;

    ll minVal = 0;
    for (ll x : minTemp)
        minVal += x;

    cout << "The maximum and minimum are " << maxVal << " and " << minVal << ".\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n;
    cin >> n;
    while (n--)
        solve();

    return 0;
}
//g++ -std=c++11 ".\10700 - Camel tradin.cpp" -o test.exe; Get-Content in.txt | .\test.exe  