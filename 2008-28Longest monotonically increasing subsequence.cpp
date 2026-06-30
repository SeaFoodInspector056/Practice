#include <bits/stdc++.h>
using namespace std;

int n, m, maxLen;
int arr[10], dp[10];
vector<int> current;
vector<vector<int>> result; 

void dfs(int idx)
{
    if (current.size() == maxLen)
    {
        result.push_back(current);
        return;
    }

    for (int i = idx; i < m; i++)
    {
        if (current.empty() or arr[i] > current.back())
            if (dp[i] >= maxLen - current.size())
            {
                current.push_back(arr[i]);
                dfs(i + 1);
                current.pop_back();//回朔找其他可能
            }   
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        result.clear();
        current.clear();
        maxLen = 0;

        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> arr[i];

        //DP代表這個數跟他之後的數可以組成最長的長度
        for (int i = m - 1; i >= 0; i--)
        {
            dp[i] = 1;
            for (int j = i + 1; j < m; j++)
                if (arr[j] > arr[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            maxLen = max(maxLen, dp[i]);
        }

        dfs(0);

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        cout << result.size() << '\n';
        
        for (vector<int>& seq : result)
        {
            for (int i = 0; i < seq.size(); i++)
            {
                if (i) 
                    cout << ' ';
                cout << seq[i];
            }

            cout << '\n';
        }
    }

    return 0;
}
//g++ -std=c++11 ".\2008-28Longest monotonically increasing subsequence.cpp" -o test.exe; Get-Content in.txt | .\test.exe