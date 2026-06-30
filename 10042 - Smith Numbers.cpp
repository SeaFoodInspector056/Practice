#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> prime(1, 2); 

void build_prime_list()
{
    for (int i = 3; i < 60000; i += 2)//60000最快
    {
        bool isPrime = true;
        for (int j = 0; (ll) prime[j] * prime[j] <= i; j++)
            if (i % prime[j] == 0)
            {
                isPrime = false;
                break;
            }
        if (isPrime)
            prime.push_back(i);
    }
}

int digit_sum (int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

bool is_prime(int x)
{
    for (int i = 0; (ll) prime[i] * prime[i] <= x; i++)
        if (x % prime[i] == 0)
            return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_prime_list();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        while (true)
        {
            n++;

            if (is_prime(n))
                continue;

            int sumDigit = digit_sum(n);
            int sumPrime = 0;

            for (int i = 0, temp = n; temp != 1; i++)
            {
                if (i >= prime.size())
                {
                    sumPrime += digit_sum(temp);//temp大到超過質數表的同時也代表temp是質數(不是的機率很小)
                    break;
                }

                if (temp % prime[i] == 0)
                {
                    temp /= prime[i];
                    sumPrime += digit_sum(prime[i]);
                    i = -1;//避免i++之後錯過prime[0] = 2
                }
            }
            
            if (sumDigit == sumPrime)
            {
                cout << n << '\n';
                break;
            }
        }
    }

    return 0;
}