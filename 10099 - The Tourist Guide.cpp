#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    int scen = 1;
    int ans;
    while (cin >> n >> r && (n || r))
    {
        vector<vector<pair<int, int>>> adj(n + 1);//存個節點的相鄰瓶頸和相鄰節點

        while (r--)
        {
            int a, b, p;
            cin >> a >> b >> p;
        
            adj[a].push_back({p, b});
            adj[b].push_back({p, a});
        }

        int s, d, t;
        cin >> s >> d >> t;

        vector<int> cap(n + 1, 0);//到達這個節點的瓶頸
        cap[s] = INT_MAX;//起始點沒有瓶頸存在

        priority_queue<pair<int, int>> pq;//存瓶頸和節點 貪心:讓瓶頸大的排前面

        pq.push({INT_MAX, s});

        while (!pq.empty())
        {
            int c = pq.top().first;//當前瓶頸
            int n = pq.top().second;//當前節點
            pq.pop();

            if (c < cap[n]) continue;//已被解決過(初始是0 如果被標記非0則為繼承其他路徑的瓶頸)

            for (int i = 0; i < adj[n].size(); i++)
            {
                int nc = adj[n][i].first;//到子節點的瓶頸
                int nn = adj[n][i].second;//子節點

                int newCap = min(c, nc);

                if (newCap > cap[nn])//代表找到了瓶頸較大的路 值得更新
                {
                    cap[nn] = newCap;
                    pq.push({newCap, nn});
                }
            }
        }

        int perTrip = cap[d] - 1;
        int ans = (t + perTrip - 1) / perTrip;//等同ans = ceil(t / perTrip)

        cout << "Scenario #" << scen++ << '\n';
        cout << "Minimum Number of Trips = " << ans << "\n\n";
    }

    return 0;
}
//g++ -std=c++11 ".\10099 - The Tourist Guide.cpp" -o test.exe; Get-Content in.txt | .\test.exe