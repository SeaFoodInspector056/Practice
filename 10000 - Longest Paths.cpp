#include <bits/stdc++.h>
using namespace std;

void dfs(int idx, const vector<vector<int>>& adj, vector<int>& dp, vector<int>& target)//int直接傳值比較快
{
    if (dp[idx] != -1) return;//未檢查過才繼續

    dp[idx] = 0;//自己到終點的距離
    target[idx] = idx;//預設自己的終點是自己

    for (int j : adj[idx])
    {
        dfs(j, adj, dp, target);//計算子節點

        //如果經由j的路徑更長，或長度相同但target編號更小
        if (dp[j] + 1 > dp[idx])    
        {
            dp[idx] = dp[j] + 1;
            target[idx] = target[j];
        }
        else if (dp[j] + 1 == dp[idx])
        {
            if (target[j] < target[idx])    
                target[idx] = target[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t = 1;
    while (cin >> n && n)
    {
        int s;
        cin >> s;

        vector<vector<int>> adj(n + 1);//第二維存可走道路就好
        vector<int> dp(n + 1, -1), target(n + 1);
        
        int p, q;
        while (cin >> p >> q && (p || q))
            adj[p].push_back(q);

        dfs(s, adj, dp, target);
        //t++很巧妙
        cout << "Case " << t++ << ": The longest path from " << s << " has length " << dp[s] << ", finishing at " << target[s] << ".\n\n";
    }

    return 0;
}
//g++ -std=c++11 "10000 - Longest Paths.cpp" -o test.exe; Get-Content in.txt | .\test.exe