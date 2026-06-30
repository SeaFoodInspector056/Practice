#include <bits/stdc++.h>
using namespace std;

double dis(double a, double b)
{
    return 2 * sqrt(a * b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;

        vector<double> radi(m);
        for (auto& x : radi)
            cin >> x;

        sort(radi.begin(), radi.end());//初始化排列

        double ans = DBL_MAX;
        do
        {
            vector<double> pos(radi.begin(), radi.end());//各圓心位置(初始對準左邊牆壁)
            for (int i = 0; i < m; i++)//現在要放的圓
                for (int j = 0; j < i; j++)//前面已經放的圓
                {
                    double temp = dis(radi[i], radi[j]) + pos[j];
                    pos[i] = max(pos[i], temp);
                }//中間小圓可能擠在左邊大圓和右邊圓的中間，故碰觸點可能還是左邊大圓的最右端決定的(故忽略小圓)
                
            double maxLen = 0;
            for (int i = 0; i < m; i++)
                maxLen = max(maxLen, radi[i] + pos[i]);//同理

            ans = min(ans, maxLen);

        } while (next_permutation(radi.begin(), radi.end()));//換下一個排列
        
        cout << fixed << setprecision(3) << ans << '\n';
    }

    return 0;
}
//++ -std=c++11 ".\10012 How Big Is It.cpp" -o test.exe; Get-Content in.txt | .\test.exe