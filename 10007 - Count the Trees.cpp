#include <bits/stdc++.h>
using namespace std;

void ctt(vector<int> &ans, int x)
{
    vector<int> nvec;
    int carry = 0;
    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        int temp = ans[i] * x + carry;
        nvec.push_back(temp % 10);
        carry = temp / 10;
    }

    while (carry)
    {
        nvec.push_back(carry % 10);
        carry /= 10;
    }

    swap(ans, nvec);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n) 
    {
        vector<int> ans(1, 1);
        for (int i = n + 2; i <= 2 * n; i++)
            ctt(ans, i);

        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\10007 - Count the Trees.cpp" -o test.exe; Get-Content in.txt | .\test.exe