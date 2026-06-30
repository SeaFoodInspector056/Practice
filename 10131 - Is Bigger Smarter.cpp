#include <bits/stdc++.h>
using namespace std;

struct ele
{
    int w, iq, id;
};

bool cmp(ele &a, ele &b)
{
    return a.w != b.w ? a.w < b.w : a.iq > b.iq;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ele> vec;

    string line;
    int i = 1;
    while (getline(cin, line))
    {   
        istringstream ss(line);
        int a, b;
        ss >> a >> b;
        vec.push_back({a, b, i++});
    }

    sort (vec.begin(), vec.end(), cmp);

    int n = vec.size();
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int maxLen = 1;
    int last = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (vec[j].w < vec[i].w && vec[j].iq > vec[i].iq)//體重越高 智商越低
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }

        if (dp[i] > maxLen) 
        {
            maxLen = dp[i];
            last = i;
        }
    }

    vector<int> path;
    int cur = last;
    while (cur != -1)
    {
        path.push_back(vec[cur].id);
        cur = parent[cur];
    }

    cout << maxLen << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << '\n';

    return 0;
}
//g++ -std=c++11 ".\10131 - Is Bigger Smarter.cpp" -o test.exe; Get-Content in.txt | .\test.exe 