#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> mp(n);
    vector<vector<int>> vec(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)//讀取地圖同時處理
    {
        getline(cin, mp[i]);
        
        for (int j = 0; j < n; j++)
            if (mp[i][j] == '*')
                for (int y = i - 1; y <= i + 1; y++)
                    for (int x = j - 1; x <= j + 1; x++)
                    {
                        if ((y == i && x == j) || y < 0 || x < 0 || y >= n || x >= n) continue;

                        vec[y][x]++;
                    }   
    }

    vector<string> touched(n);
    bool touchedBoom = false;
    for (int i = 0; i < n; i++)//讀取觸摸boom
    {
        getline(cin, touched[i]);
        
        for (int j = 0; j < n; j++)
            if (touched[i][j]  == 'x' && mp[i][j] == '*')
            {
                touchedBoom = true;
                break;
            }
    }

    for (int i = 0; i < n; i++)//輸出
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] == '*' && touchedBoom) cout << '*';
            else if (touched[i][j] == 'x') cout << vec[i][j];
            else cout << '.';
        }

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
//++ -std=c++11 ".\10279 - Mine Sweeper.cpp" -o test.exe; Get-Content in.txt | .\test.exe