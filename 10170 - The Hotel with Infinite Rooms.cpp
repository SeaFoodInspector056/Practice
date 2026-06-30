#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s, d;
    while (cin >> s >> d)
    {
        while (d > 0)
            d -= s++;

        cout << s - 1 << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10170 - The Hotel with Infinite Rooms.cpp" -o test.exe; Get-Content in.txt | .\test.exe