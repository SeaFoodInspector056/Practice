#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0)
    {
        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        
        sort(s.begin(), s.end());
        s.erase (unique(s.begin(), s.end()), s.end()); //去重所有元素 (都在S) 注意s的長度改變!!!
        
        map<int, pair<int,int>> ab_map; //把總和存起來 (順便保存a, b值) 附帶自動sort
        for (int i = 0; i < s.size(); i++) 
            for (int j = 0; j < s.size(); j++)
            {
                if (i == j) continue;
                ab_map[s[i] + s[j]] = {s[i], s[j]};
            }
        
        int ans;
        bool found = false;
        
        for (int i = s.size()- 1; i >= 0 and !found ; i--)// d
            for (int j = 0; j < s.size(); j++)// c
            {
                if (i == j) continue;

                int need = s[i] - s[j];// d - c = a + b

                if (ab_map.count(need))// O(log n) map是紅黑樹
                {
                    int a = ab_map[need].first;
                    int b = ab_map[need].second;
                    // 確保 a,b,c,d 四個都不同
                    if (a != s[i] && a != s[j] && b != s[i] && b != s[j] && a != b)
                    {
                        ans = s[i];
                        found = true;
                        break;
                    }
                }
            }
        
        if (found) cout << ans << '\n';
        else cout << "no solution" << '\n';
    }

    return 0;
}