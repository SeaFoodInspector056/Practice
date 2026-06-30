#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l, r, c;
    while (cin >> l >> r >> c)
    {
        if (l == 0 and r == 0 and c == 0) break;

        int si, sj, sk, ei, ej, ek;
        char arr[l][r][c];
        int dp[l][r][c];
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++) 
                for (int k = 0; k < c; k++) 
                {
                    cin >> arr[i][j][k];

                    dp[i][j][k] = -1;  // -1 代表未走過

                    if (arr[i][j][k] == 'S') 
                    { 
                        si = i; 
                        sj = j; 
                        sk = k; 
                    }
                    else if (arr[i][j][k] == 'E') 
                    { 
                        ei = i;
                        ej = j; 
                        ek = k; 
                    }
                }

        // BFS
        queue<tuple<int,int,int>> q;
        q.push({si, sj, sk});
        dp[si][sj][sk] = 0;

        int z, x, y;
        int dz[] = {-1, 1, 0, 0, 0, 0};
        int dx[] = {0, 0, -1, 1, 0, 0};
        int dy[] = {0, 0, 0, 0, -1, 1};
        while (!q.empty()) 
        {
            z = get<0>(q.front());
            x = get<1>(q.front());
            y = get<2>(q.front());
            q.pop();

            for (int i = 0; i < 6; i++) 
            {
                int nz = z + dz[i];
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c)
                    continue;
                else if (arr[nz][nx][ny] == '#') 
                    continue;
                else if (dp[nz][nx][ny] != -1) //已經被最短路徑找到了
                    continue;

                dp[nz][nx][ny] = dp[z][x][y] + 1;

                q.push({nz, nx, ny});
            }
        }

        if (dp[ei][ej][ek] != -1)
            cout << "Escaped in " << dp[ei][ej][ek] << " minute(s).\n";
        else 
            cout << "Trapped!\n";

    }

    return 0;
}