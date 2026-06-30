#include <bits/stdc++.h>
using namespace std;

//這些陣列太大了!!main()的stack只有大約2MB
const int N_MAX = 1000000;
double dp1[N_MAX + 1];//都沒取到red的機率
double dp2[N_MAX + 1];//全部都red的機率(用log10存取)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp1[0] = 1.0;
    dp2[0] = 0;

    for (int i = 1; i <= N_MAX; i++)//取到兩個red的機率: 1 / (i * (i + 1))
    {
        dp1[i] = dp1[i - 1] * (1.0 - 1.0 / ((double)i * (i + 1)));
        dp2[i] = dp2[i - 1] - log10((double)(i) * ((double)(i) + 1.0));
    }

    int n;
    while (cin >> n)
    {   
        int z = (int)ceil(-dp2[n]) - 1;
        cout << fixed << setprecision(6) << 1 - dp1[n] << " " << z << '\n'; 
    }

    return 0;
}
//g++ -std=c++11 ".\10169 - Urn-ball Probabilitiesa!.cpp" -o test.exe; Get-Content in.txt | .\test.exe