#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int dp[n], maxLen = 0;
    for (int L = n - 1; L >= 0 ; L--)//是i--!
    {
        dp[L] = 1;//由最右到L的最長長度
        for (int R = L + 1; R < n; R++)
            if (arr[L] < arr[R])
                dp[L] = max(dp[L], dp[R] + 1);
        
        maxLen = max(dp[L], maxLen);
    }

    cout << maxLen;

    return 0;
}