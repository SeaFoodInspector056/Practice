#include <iostream>
using namespace std;

char arr[105][105] = {'*'};
int dp[105][105] = {0};
int m, n;
void dfs (int i, int j)
{
    if (i < 1 or i > n+1 or j < 1 or j > m+1) return;
    if (dp[i][j] == 1 or arr[i][j] == '*') return;//遇到沒油田無意義 或被搜尋到的就剛好連上了

    dp[i][j] = 1;

    for (int k = i-1; k <= i+1; k++)
        for (int l = j-1; l <= j+1; l++)
            dfs(k, l);
}


int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n+2; i++)
            for (int j = 0; j < m+2; j++)
            {
                arr[i][j] = '*';//初始化為'*'，代表沒有油田
                dp[i][j] = 0;//初始化為0，代表沒有被訪問過
            }

        for (int i = 1; i < n+1; i++)
            for (int j = 1; j < m+1; j++)
                cin >> arr[i][j];

        int count = 0;
        for (int i = 1; i < n+1; i++)
            for (int j = 1; j < m+1; j++)
            {
                if (arr[i][j] == '@' and dp[i][j] == 0)
                {
                    count++;
                    dfs(i, j);
                }
            }

        cout << count << endl;
    }
    return 0;
}