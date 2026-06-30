#include <bits/stdc++.h>
using namespace std;

vector<int> smallPrimeList(1, 2);

//2,147,483,647 int的上限取根號 約46341
void create_smallPrimeList()
{
    for (long long i = 3; i * i <= 2147483647; i += 2)
    {
        bool flag = true;
        for (int j = 0; j < smallPrimeList.size() && smallPrimeList[j] * smallPrimeList[j] <= i; j++)
            if (i % smallPrimeList[j] == 0) 
            {
                flag = false;
                break;
            }
        
        if (flag)
            smallPrimeList.push_back(i);
    }
}

//檢查區間元素是否為質數或合數
void sieve_prime(int L, int U, vector<bool> &sieve)
{
    for (int &p : smallPrimeList)
    {
        //p * p倍數開始的數(前面已經被(更小的數) * p檢查了, 第一個大於L的倍數
        long long start = max((long long)p * p, ((long long)L + p - 1) / p * p);
        for (long long j = start; j <= U; j += p)
            sieve[j - L] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    create_smallPrimeList();

    int L, U;
    while (cin >> L >> U)
    {   
        int len = U - L + 1;

        vector<bool> sieve(len, true);
        if (L == 1) sieve[0] = false;
        sieve_prime(L, U, sieve);

        vector<int> primeList;
        for (int i = 0; i < len; i++)
            if (sieve[i]) primeList.push_back(i + L);

        if (primeList.size() < 2) 
        {
            cout << "There are no adjacent primes.\n";
            continue;
        }

        int minDif = INT_MAX, maxDif = 0;
        int clo, far;
        for (int i = 1; i < primeList.size(); i++)
        {
            int dif = primeList[i] - primeList[i - 1];
            if (dif < minDif)
            {
                minDif = dif;
                clo = i;
            }
            if (dif > maxDif)
            {
                maxDif = dif;
                far = i;
            }
        }

        cout << primeList[clo - 1] << ',' << primeList[clo] << " are closest, ";
        cout << primeList[far - 1] << ',' << primeList[far] << " are most distant.\n";
    }

    return 0;
}
//g++ -std=c++11 ".\10140 - Prime Distance.cpp" -o test.exe; Get-Content in.txt | .\test.exe