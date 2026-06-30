#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0)
    {
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> course(5);
            for (int &x : course)
                cin >> x;

            sort(course.begin(), course.end());

            mp[course]++;
        }

        int maxStu = 0;
        for (auto &x : mp)
            maxStu = max(maxStu, x.second);

        int ans = 0;
        for (auto &x : mp)
            if (x.second == maxStu)
                ans += x.second;

        cout << ans << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\11286 - Conformity.cpp" -o test.exe; Get-Content in.txt | .\test.exe