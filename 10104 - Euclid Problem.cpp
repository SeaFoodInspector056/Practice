#include <bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else 
    {
        int nx, ny;
        int nd = exgcd(b, a % b, nx, ny);
        x = ny;
        y = nx - (a / b) * ny;
        return nd;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b)
    {   
        int x, y;

        int d = exgcd(a, b, x, y);

        cout << x << ' ' << y << ' ' << d << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10104 - Euclid Problem.cpp" -o test.exe; Get-Content in.txt | .\test.exe