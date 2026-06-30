#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (cin >> s)
    {
        int n = s.size();
        int p_start; 

        for (int i = 0; i < n; i++)
        {
            bool is_pld = true;
            int L = i, R = n - 1;
            
            while (L < R)
            {
                if (s[L] != s[R])
                {
                    is_pld = false;
                    break;
                }
                
                L++;
                R--;
            }

            if (is_pld)
            {
                p_start = i; // 找到了最靠左（最長）的回文後綴起點
                break;
            }
        }

        cout << s;
        for (int i = p_start - 1; i >= 0; i--)
            cout << s[i];
        cout << '\n';
    }

    return 0;
}