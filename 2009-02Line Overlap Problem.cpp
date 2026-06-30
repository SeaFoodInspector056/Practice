#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> seg;//紀錄位置 and 起點or終點

    string buf;
    while (getline(cin, buf) && buf != ".")
    {
        istringstream ss(buf);
        int L, R;
        ss >> L >> R;

        seg.push_back({L, 1});
        seg.push_back({R, -1});
    }

    sort(seg.begin(), seg.end(), cmp);

    int cnt = 0, index = 0;
    long long ans = 0;
    for (auto &x : seg)
    {
        if (x.first > index && cnt >= 2)
            ans += (x.first - index) * (cnt * (cnt - 1) / 2);//長度乘上組合數
        
        cnt += x.second;
        index = x.first;
    }
    
    cout << ans << '\n';

    return 0;
}
//g++ -std=c++11 ".\2009-02Line Overlap Problem.cpp" -o test.exe; Get-Content in.txt | .\test.exe