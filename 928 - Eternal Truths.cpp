#include <bits/stdc++.h>
using namespace std;

struct bfsStruct
{
    int y, x, step;

    bfsStruct(int _y, int _x, int _step) : y(_y), x(_x), step(_step) {}//冒號初始化的意思
};

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<vector<int>>> move(r, vector<vector<int>>(c, vector<int>(4, -1)));

    int sy, sx, ey, ex;

    for (int i = 0; i < r; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < c; ++j)
            maze[i][j] = line[j];

        for (int j = 0; j < c; ++j)
        {
            if (maze[i][j] == 'S') 
            {
                sy = i;
                sx = j;
            }
            else if (maze[i][j] == 'E')
            {
                ey = i;
                ex = j;
            }
        }        
    }       

    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    queue<bfsStruct> bfs;
    bfs.push({sy, sx, 0});
    move[sy][sx][0] = 0;

    int ans = -1;
    while (!bfs.empty())
    {
        int y = bfs.front().y;
        int x = bfs.front().x;
        int step = bfs.front().step;
        bfs.pop();

        if (maze[y][x] == 'E') 
        {
            ans = move[y][x][step];
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y;
            int nx = x;
            int nstep = step % 3 + 1;//1, 2, 3, 1, 2, 3...

            bool inValid = false;
            for (int j = 0; j < nstep; j++)
            {
                ny += dy[i];
                nx += dx[i];
                if (ny >= r || ny < 0 || nx >= c || nx < 0 || maze[ny][nx] == '#') 
                {
                    inValid = true;
                    break;
                }
            }
            if (inValid) continue;
            
            if (move[ny][nx][nstep] != -1) continue; 

            move[ny][nx][nstep] = move[y][x][step] + 1;

            bfs.push({ny, nx, nstep});
        }

    }

    if (ans != -1) cout << ans << '\n';
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
//g++ -std=c++11 ".\928 - Eternal Truths.cpp" -o test.exe; Get-Content in.txt | .\test.exe 