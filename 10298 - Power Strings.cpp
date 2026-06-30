#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != ".")
    {
        int n = s.size();
        vector<int> fail(n, 0);//最長相同prefix和suffix的長度 和比對失敗的時候要在哪一個index

        for (int i = 1; i < n; i++)//慢慢加長比對的字串長度a, ab, aba...
        {   
            int len = fail[i - 1];
            while (len > 0 && s[i] != s[len]) len = fail[len - 1];//如果不匹配就回朔(縮小長度)
            if (s[i] == s[len]) len++;//相同則長度+1(因為i++多取一個元素進去判斷)
            fail[i] = len;
        }

        int unit = n - fail[n - 1];//總長度減最長重疊相當於平移了多少會同樣對齊
        // a b c a b c . . .往右3格剛好又對齊了
        // . . . a b c a b c往左3格剛好又對齊了
        if (n % unit == 0) cout << n / unit << '\n';
        else cout << 1 << '\n';//ababa不能用ab重複
    }

    return 0;
}//記得前綴後綴都是由左往右讀字串 後綴不是反過來讀字串
//g++ -std=c++11 ".\10298 - Power Strings.cpp" -o test.exe; Get-Content in.txt | .\test.exe