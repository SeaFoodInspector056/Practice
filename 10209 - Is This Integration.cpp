#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, pi = acos(-1.0);
    while (cin >> a)
    {
        double A = a*a*(pi/3 + 1 - sqrt(3));
        double B = a*a*(pi/12 - 1 + sqrt(3)/2);
        double C = a*a*(1 - sqrt(3)/4- pi/6);
        cout << fixed << setprecision(3) << A << ' ' << B * 4 << ' ' << C * 4 << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10209 - Is This Integration.cpp" -o test.exe ; Get-Content in.txt | .\test.exe 