#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    while (cin >> n && n != 0)
    {
        if (sqrt(n) == static_cast<unsigned int>(sqrt(n)))//代表為完全平方數
            cout << "yes\n";
        else 
            cout << "no\n";   
    }

    return 0;
}
//g++ -std=c++11 "10110 - Light, more light.cpp" -o test.exe ; Get-Content in.txt | .\test.exe
