#include <bits/stdc++.h> 
using namespace std;
//這題不知道要不要long long
bool cmp(vector<int> &a, vector<int> &b)
{
    return a.size() == b.size() ? a < b : a.size() < b.size();//vector物件可直接比較大小 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;
    string buf;
    while (getline(cin, buf))
    {
        if (buf[0] == '.') break;

        vec.clear();
        buf.erase(buf.begin());
        buf.erase(buf.end() - 1);//end()指的是最後一個元素的下一位

        istringstream ss(buf);
        int x;
        while (ss >> x)
            vec.push_back(x);

        int n = vec.size();
        int tot = 0;
        for (int &x : vec)
            tot += x;
        
        if (tot % 2 != 0)
        {
            cout << "No such subset\n";
            continue;
        }

        //開始計算各種可能
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); i++)
        {
            vector<int> cur;
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                {
                    sum += vec[j];
                    cur.push_back(vec[j]);
                }

            if (sum == tot / 2)
                ans.push_back(cur);
        }   

        sort(ans.begin(), ans.end(), cmp);

        if (ans.empty())
        {
            cout << "No such subset\n";
            continue;
        }

        cout << ans.size() << " subsets.\n";
        for (auto &x : ans)
        {
            cout << '{';
            for (int i = 0; i < x.size(); i++)
            {
                if (i) cout << ' ';
                cout << x[i];
            }
            cout << "}\n";
        }
        cout << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\2008-19Set partition.cpp" -o test.exe; Get-Content in.txt | .\test.exe