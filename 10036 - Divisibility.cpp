#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    while (m--) 
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            arr[i] = (arr[i] % k + k) % k; //只留下餘數
        }

        vector<vector<bool>> f(n, vector<bool>(k, 0)) ;

        f[0][arr[0]] = true;
        for (int i = 1; i < n; i++) 
            for (int j = 0; j < k; j++)   
                if (f[i - 1][(((j + arr[i]) % k + k) % k)]) 
                    f[i][j] = true;
                else if (f[i - 1][(((j - arr[i]) % k + k) % k)])//如果加某數 則假設這樣的餘數減現在多加的餘數有沒有合法的餘數存在
                    f[i][j] = true;

        cout << (f[n - 1][0] ? "Divisible\n" : "Not divisible\n");
    }

    return 0;
}//核心觀念:檢驗餘數相加相減之後是否存在，因為只是要找有沒有一種可能是整除的