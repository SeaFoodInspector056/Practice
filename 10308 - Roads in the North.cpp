#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> road;
int maxLen = 0;

int dfs(int index, int father)
{
    int max1 = 0;
    int max2 = 0;
    for (auto &x : road[index])
    {
        int vil = x.first;
        if (vil == father) continue;
        
        int dis = x.second;
        int pathLen = dfs(vil, index) + dis;

        if (pathLen > max1)
        {
            max2 = max1;
            max1 = pathLen;
        }
        else if (pathLen > max2)
            max2 = pathLen;
    }

    maxLen = max(maxLen, max1 + max2);//子節也可以組成一條路(如果有max2存在的話)

    return max1;//回傳最長的子節繼續找
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line))
    {
        if (line.empty())//代表一個測資輸入結束
        {
            dfs(road.begin() -> first, -1);

            cout << maxLen << '\n';
            //初始化
            road.clear();
            maxLen = 0;
        }
        else//輸入測資資料
        {
            int n, m, l;
            istringstream ss(line);
            ss >> n >> m >> l;
            road[n].push_back({m, l}); 
            road[m].push_back({n, l}); 
        } 
    }
    dfs(road.begin() -> first, -1);//用指標->

    cout << maxLen << '\n';//EOF後的最後一次

    return 0;
}
//g++ -std=c++11 ".\10308 - Roads in the North.cpp" -o test.exe; Get-Content in.txt | .\test.exe