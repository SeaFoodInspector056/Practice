#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n)
    {
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        sort(v.begin(), v.end());

        int lowmid, himid;
  
        if (n % 2 == 0)
        {
            lowmid = v[n / 2 - 1];
            himid = v[n / 2];
        }
        
        else 
        {
            lowmid = v[n / 2];
            himid = lowmid;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++)
            if (v[i] == lowmid || v[i] == himid)
                count++;

        cout << lowmid << ' ' << count << ' ' << himid - lowmid + 1 << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10057 - A mid-summer nights dream.cpp" -o test.exe
//Get-Content in.txt | .\test.exe