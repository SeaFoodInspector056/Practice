#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (getline(cin, a))
    {
        getline(cin, b);
        
        vector<int> vecA(26, 0), vecB(26, 0);
        
        auto get_alpha = [](string &s, vector<int> &vec)
        {
            for (int i = 0; i < s.size(); i++)
                vec[s[i] - 'a']++;
        };

        get_alpha(a, vecA);
        get_alpha(b, vecB);

        string ans;
        for (int i = 0; i < 26; i++)
            while (vecA[i] > 0 && vecB[i] > 0)
            {
                ans += (char)(i + 'a');
                vecA[i]--;
                vecB[i]--;
            }
        
        cout << ans << '\n';
    }

    return 0;
}
//++ -std=c++11 ".\10252 - Common Permutation.cpp" -o test.exe; Get-Content in.txt | .\test.exe