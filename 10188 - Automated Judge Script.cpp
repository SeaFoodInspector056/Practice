#include <bits/stdc++.h>
using namespace std;

string find_digit(vector<string> &vs)
{
    string res;
    for (auto &x : vs)
        for (auto &y : x)
            if (isdigit(y))
                res += y;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t = 1;
    while (cin >> n && n)
    {
        cin.ignore();

        cout << "Run #" << t++ << ": ";

        vector<string> ans(n);
        for (int i = 0; i < n; i++)
            getline(cin, ans[i]);

        int m;
        cin >> m;
        cin.ignore();
        vector<string> sub(m);
        for (int i = 0; i < m; i++)
            getline(cin, sub[i]);
        
        if (ans == sub) cout << "Accepted\n";
        else if (find_digit(ans) == find_digit(sub)) cout << "Presentation Error\n";
        else cout << "Wrong Answer\n";
    }

    return 0;
}   
//g++ -std=c++11 ".\10188 - Automated Judge Script.cpp" -o test.exe; Get-Content in.txt | .\test.exe