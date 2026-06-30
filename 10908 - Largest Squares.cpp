#include <bits/stdc++.h>

using namespace std;

int m, n, q;
vector<vector<char>> chart;

//檢測r是否合法
int find_square(const int& x, const int& y, const int r)
{
    for (int i = y - r; i <= y + r; i++)
        for (int j = x - r; j <= x + r; j++)
        {
            if (i >= m || i < 0 || j >= n || j < 0) return r - 1;
            if (chart[i][j] != chart[y][x]) return r - 1;
        }
        
    return find_square(x, y, r + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> q;
        cout << m << ' ' << n << ' ' << q << '\n';

        chart.assign(m, vector<char>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> chart[i][j];
        
        while (q--)
        {
            int x, y;
            cin >> x >> y;

            int r = 1;
            int ans = find_square(y, x, r);

            cout << ans * 2 + 1 << '\n';
        }
    }

    return 0;
}
//g++ -std=c++11 ".\10908 - Largest Squares.cpp" -o test.exe
//Get-Content in.txt | .\test.exe