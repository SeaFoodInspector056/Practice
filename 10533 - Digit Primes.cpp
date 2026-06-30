#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int maxNum = 1000000;

vector<int> smallPrime(1, 2);
vector<int> prime(1, 2);
vector<int> digitPrime;

void sieve_prime()
{
    for (ll i = 3; i * i < maxNum; i += 2)
    {
        bool flag = true;
        for (int j = 0; j < smallPrime.size(); j++)
            if (i % smallPrime[j] == 0)
            {
                flag = false;
                break;
            }
            
        if (flag) smallPrime.push_back(i);
    }

    vector<bool> boolSieve(maxNum + 1, true);
    for (ll i = 0; i < smallPrime.size(); i++)
        for (ll j = smallPrime[i]; smallPrime[i] * j <= maxNum; j++)//i是index!!!!
            boolSieve[smallPrime[i] * j] = false;


    for (int i = 3; i <= maxNum; i += 2)
        if (boolSieve[i] == true) prime.push_back(i);
}

int digit_sum(int num)
{
    int res = 0;
    while (num > 0)
    {
        res += num % 10;
        num /= 10;
    }

    return res;
}

void digit_prime()
{
    for (int i = 0; i < prime.size(); i++)
    {
        int digitSum = digit_sum(prime[i]);
        bool flag = true;
        for (int j = 0; j < prime.size() && (ll)(prime[j]) * prime[j] <= digitSum; j++)
            if (digitSum % prime[j] == 0)
            {
                flag = false;
                break;
            }
        
        if (flag) digitPrime.push_back(prime[i]);
    }
}

void solve()
{
    int lo, hi;
    cin >> lo >> hi;

    auto l = lower_bound(digitPrime.begin(), digitPrime.end(), lo);//回傳的是迭代器 要用auto
    auto r = upper_bound(digitPrime.begin(), digitPrime.end(), hi);

    cout << r - l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_prime();
    digit_prime();

    int n;
    cin >> n;
    while (n--) solve();

    return 0;
}