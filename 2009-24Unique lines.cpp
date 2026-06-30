#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    set<tuple<int,int,int>> v;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x[n], y[n];
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int a = x[j] - x[i];
                int b = y[j] - y[i];

                int c = x[j]*y[i] - x[i]*y[j];

                int g = gcd(gcd(abs(a), abs(b)), abs(c));
                if (g!= 0)
                {
                    a /= g;
                    b /= g;
                    c /= g;
                }

                if (a < 0 or (a == 0 and b < 0))
                {
                    a = -a;
                    b = -b;
                    c = -c;
                }

                v.insert({a, b, c}); 
            }

        cout << v.size()  << '\n';

    }
    return 0;
}
