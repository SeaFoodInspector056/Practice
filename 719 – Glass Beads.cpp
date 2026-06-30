#include <bits/stdc++.h>
using namespace std;

int solve()
{
    string s;
    cin >> s;
    
    int len = s.size();
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len)
    {
        char a = s[(i + k) % len];
        char b = s[(j + k) % len];

        //如果找到序列高的 就直接跳轉這個序列前面比較過的跟當下比較的 並保留小的序列跟新的序列繼續必較
        if (a == b)
            k++;
        else
        {
            if (a > b)//蛋雕必較大的
                i += k + 1;//k同時代表前面必較過的累積長度
            else if (a < b)
                j += k + 1;
            
            if (i == j)
                j++;
            
            k = 0;
        }
    }

    //如果是i超過 那就是j是答案(j同時也較小)
    //反之就是i
    //如果都完全同樣且是最小排序就取索引值最小值
    return min(i, j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
        cout << solve() + 1 << '\n';

    return 0;
}
//g++ -std=c++11 ".\719 – Glass Beads.cpp" -o test.exe; Get-Content in.txt | .\test.exe