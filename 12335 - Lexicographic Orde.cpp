#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll permuList[21];//各種數量的排列可能數量

void permutation()
{
    permuList[0] = 1;
    for (int i = 1; i <= 20; i++)
        permuList[i] = permuList[i - 1] * i;
}

void solve(int i)
{
    string s;
    ll k;
    cin >> s >> k;
    k--;//轉成在index裡!!

    int ssize = s.size();
    vector<int> pos(ssize);
    for (int i = 0; i < ssize; i++)
        pos[i] = i;//[0, 1, 2...] 

    vector<char> ans(ssize);//原本的排列

    for (int i = 0; i < ssize; i++)
    {
        ll temp = permuList[ssize - 1 - i];//多少可能之後才會在這個位置排序下一個字母
        int idx =  k / temp;

        ans[pos[idx]] = s[i];//所以我們知道是取ans原本的第幾個char放進s的第一個etc.

        pos.erase(pos.begin() + idx);//被取過了所以直接不用考慮(erase)
        k %= temp;
    }

    cout << "Case " << i << ": ";
    for (char x : ans)
        cout << x;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    permutation();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}
//g++ -std=c++11 ".\12335 - Lexicographic Orde.cpp" -o test.exe; Get-Content in.txt | .\test.exe