#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> tokens;
int pos;

ll solve()
{
    string token = tokens[pos--];

    if (token != "+" && token != "-" && token != "*" && token != "/")  
        return stoi(token);

    else
    {
        ll right = solve();
        ll left = solve();

        if (token == "+") return left + right;
        if (token == "-") return left - right;
        if (token == "*") return left * right;
        if (token == "/") return left / right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    istringstream ss(s);
    string token;
    while (ss >> token)
        tokens.push_back(token);

    pos = tokens.size() - 1;
    ll result = solve();

    cout << result;

    return 0;
}
