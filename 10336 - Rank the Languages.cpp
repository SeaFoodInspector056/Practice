#include <bits/stdc++.h>
using namespace std;

int w, c; 

void checking(int x, int y, char& target, vector<vector<bool>>& checked, vector<vector<char>>& arr)//&比較快
{
    if (x >= w || x < 0 || y >= c || y < 0) return;
    if (checked[x][y] == true || arr[x][y] != target) return;

    checked[x][y] = true;

    int a[4] = {1, -1, 0, 0};
    int b[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
        checking(x + a[i], y + b[i], arr[x][y], checked, arr);//1.不要忘記[] 2.x + a[i]是一個臨時值 沒有記憶體空間所以不能用&
}

bool cmp(pair<char, int>& a, pair<char, int>& b)
{
    if (a.second != b.second) return  a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> w >> c;
  
        vector<vector<char>> arr(w, vector<char>(c));
        vector<vector<bool>> checked(w, vector<bool>(c, false));
        map<char, int> mp;

        for (int a = 0; a < w; a++)
        {
            string s;
            cin >> s;
            for (int b = 0; b < c; b++)
                arr[a][b] = s[b];
        }

        for (int a = 0; a < w; a++)
            for (int b = 0; b < c; b++)
                if (checked[a][b] == false)
                {
                    checking(a, b, arr[a][b], checked, arr);
                    mp[arr[a][b]]++;
                }
        
        vector<pair<char, int>> mtov(mp.begin(), mp.end());
        sort(mtov.begin(), mtov.end(), cmp);

        cout << "World #" << i << '\n';
        for (auto k : mtov)
            cout << k.first << ": " << k.second << "\n";
    }

    return 0;
}
//g++ -std=c++11 "10336 - Rank the Languages.cpp" -o test.exe; Get-Content in.txt | .\test.exe