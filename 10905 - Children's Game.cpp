#include <bits/stdc++.h>
using namespace std;

// s1 == 900, s2 = 9
// s1 + s2 = 9900 ; s2 + s1 = 9009 不等式成立 讓s1排在前面
bool cmp(string &s1, string &s2)
{
    return s1 + s2 > s2 + s1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n)
    {
        vector<string> vec(n);
        for (auto &s : vec)
            cin >> s;

        sort(vec.begin(), vec.end(), cmp);

        for (auto &s : vec)
            cout << s;
        cout << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10905 - Children's Game.cpp" -o test.exe; Get-Content in.txt | .\test.exe