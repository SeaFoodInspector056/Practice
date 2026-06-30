#include <bits/stdc++.h>
using namespace std;

vector<int> primeList(1, 2);
void build_primeList()
{
    for (int i = 3; i < 10000; i += 2)
    {
        bool isPrime = true;
        for (int j = 0; primeList[j] * primeList[j] <= i; j++)
            if (i % primeList[j] == 0)
            {
                isPrime = false;
                break;
            }
        if (isPrime)
            primeList.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_primeList();
    
    int primeSize = primeList.size();

    //質數表連續前綴和
    vector<int> dp(primeSize + 1, 0);
    for (int i = 1; i <= primeSize; i++)
        dp[i] = dp[i - 1] + primeList[i - 1];

    int n;
    while (cin >> n && n != 0)
    {
        int count = 0;
        
        //前綴和互減得到各種連續質數和組合
        for (int i = 0; i < primeSize; i++)
            for (int j = i + 1 ; j <= primeSize; j++)
            {
                if (dp[j] - dp[i] == n)
                {
                    count++;
                    break;
                }

                if (dp[j] - dp[i] > n) break;
            }

        cout << count << '\n';
    }

    return 0;
}
//g++ -std=c++11 "1210 - Sum of Consecutive Prime Numbers.cpp" -o test.exe; Get-Content in.txt | .\test.exe