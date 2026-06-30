#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m;
    cin >> m;

    vector<pair<int, int>> seg;
    int L, R;
    while (cin >> L >> R && (L || R))
        seg.push_back({L, R});

    sort(seg.begin(), seg.end());//照起點小到大排序 同起點的終點也小到大排序(讓greedy好發揮)

    vector<pair<int, int>> ans;
    int l = 0, r = 0;
    int n = seg.size();

    for (int i = 0; i < n; i++)
    {
        int p = -1;

        while (i < n && seg[i].first <= l)//尋找在起點包含l的情況下 終點最遠的的線段
        {
            if (seg[i].second > r)
            {
                r = seg[i].second;
                p = i;
            }
            
            i++;
        }
        i--;

        if (p == -1) break;//代表啥都沒找到

        ans.push_back(seg[p]);

        if (r >= m) break;//覆蓋到M就跳出

        l = r;
    }//greedy選最後一個也要右端最大(題目沒有講但是這樣)

    if (r < m)
        cout << "0\n\n";
    else 
    {
        cout << ans.size() << '\n';
        for (auto &x : ans)
            cout << x.first << ' ' << x.second << '\n';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
//g++ -std=c++11 ".\10020 - Minimal Coverage.cpp" -o test.exe; Get-Content in.txt | .\test.exe        