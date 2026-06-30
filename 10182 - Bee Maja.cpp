#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        int x = 0, y = 0;
        if (n == 1)
        {
            cout << x << ' '  << y << '\n';
            continue;
        }

        int lev = 0;
        int tot = 1;
        while (n > tot)
        {
            n -= tot;
            lev++;
            //當前層的全部數量
            tot = lev * 6;
        }

        if (n <= lev * 1)
        {
            x = lev - n;
            y = n;
        }
        else if (n <= lev * 2)
        {
            x = lev - n;
            y = lev;
        }
        else if (n <= lev * 3)
        {
            x = -lev;
            y = lev * 3 - n;
        }
        else if (n <= lev * 4)
        {
            x = n - lev * 4;
            y = lev * 3 - n;
        }
        else if (n <= lev * 5)
        {
            x = n - lev * 4;
            y = -lev;
        }
        else if (n <= lev * 6)
        {
            x = lev;
            y = n - lev * 6;
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10182 - Bee Maja.cpp" -o test.exe; Get-Content in.txt | .\test.exe