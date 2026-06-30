#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {   
        int arr[m], dp[n+1]; //dp[i]代表我的回合剩下這些石頭時，我是否必輸(對方夠聰明可以必贏)

        for (int i = 0; i < m; i++)
            cin >> arr[i];
        
        sort(arr, arr + m); 

        dp[0] = 0; //0代表必輸
        dp[1] = 1; //1代表必勝
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0; //預設必輸
            for (int j = 0; j < m && arr[j] <= i; j++)
            {
                int flag = !(dp[i - arr[j]]);//對我來說，找到一個對方的dp是0的就好
                if (flag == 1)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        cout << (dp[n] ? "Stan wins" : "Ollie wins") << endl;
    }
    return 0;

}