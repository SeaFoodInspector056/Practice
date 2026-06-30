#include <bits/stdc++.h>
using namespace std;

int N_MAX = 10000;

vector<int> digitSum(N_MAX + 1, 0);

void build_vec()
{
    digitSum[0] = 1;

    vector<int> vec(1, 1);
    vector<int> nvec;
    for (int i = 1; i <= N_MAX; i++)
    {
        nvec.clear();
        int carry = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            int cur = vec[j] * i + carry;
            digitSum[i] += cur % 10;
            nvec.push_back(cur % 10);
            carry = cur / 10;
        }

        while (carry > 0)//進位有可能超過十位數ex. 9 *999(最後收尾)
        {
            digitSum[i] += carry % 10;
            nvec.push_back(carry % 10);
            carry /= 10;
        }

        swap(vec, nvec);//swap比較快
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_vec();

    int n;
    while (cin >> n) cout << digitSum[n] << '\n';

    return 0;
}
//g++ -std=c++11 ".\10220 - I Love Big Numbers.cpp" -o test.exe; Get-Content in.txt | .\test.exe