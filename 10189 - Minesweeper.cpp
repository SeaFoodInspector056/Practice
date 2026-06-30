#include <bits/stdc++.h>
using namespace std;

int n, m;

void update(int y, int x, vector<vector<int>>& field)
{
    field[y][x] = -1;

    for (int i = y - 1; i <= y + 1; i++)
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (i < 0 || j < 0 || i >= n || j >= m || field[i][j] == -1) continue;
            
            field[i][j]++;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        cin.ignore();//記得!!!

        vector<vector<int>> field(n, vector<int>(m, 0));

        if (t != 1)
            cout << '\n';

        string line;
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            for (int j = 0; j < m; j++)
                if (line[j] == '*')
                    update(i, j, field);
        }

        cout << "Field #" << t++ << ":\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (field[i][j] != -1)
                    cout << field[i][j];
                else    
                    cout << '*';
            }

            cout << '\n';
        }
    }

    return 0;
}
//++ -std=c++11 ".\10189 - Minesweeper.cpp" -o test.exe; Get-Content in.txt | .\test.exe