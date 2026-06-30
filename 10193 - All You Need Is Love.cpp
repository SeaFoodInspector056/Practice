#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int p = 1; p <= n; p++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int size1 = s1.size(), size2 = s2.size();
        int n1 = 0, n2 = 0;

        for (int i = 0; i < size1; i++)
            n1 += (s1[i] - '0' << (size1 - i - 1));
        for (int i = 0; i < size2; i++)
            n2 += (s2[i] - '0' << (size2 - i - 1));

        int gcd = __gcd(n1, n2);

        cout << "Pair #" << p << ": ";
        if (gcd == 1)
            cout << "Love is not all you need!\n";
        else 
            cout << "All you need is love!\n";
    }

    return 0;
}
//g++ -std=c++11 ".\10193 - All You Need Is Love.cpp" -o test.exe; Get-Content in.txt | .\test.exe