#include <bits/stdc++.h>
using namespace std;

struct Contestant1
{
    //記得在struct初始化vector要用= 因為vector()本質是呼叫函式 struct只能宣告
    vector<int> probCondi = vector<int>(10, 0);//錯誤-1 未回答0 正確1
    vector<int> triedBeforeAC = vector<int>(10, 0);//AC前的錯誤次數(I) AC後才加進ttime
    int ttime = 0;
};

struct Contestant2
{
    int id = 0, solve = 0, ttime = 0;
    bool tried = false;//是否有送出過(try是原本的C++原生函式)
};

bool cmp(Contestant2 &a, Contestant2 &b)
{
    if (a.solve != b.solve) return a.solve > b.solve;
        
    if (a.ttime != b.ttime) return a.ttime < b.ttime;

    return a.id < b.id;
}

void solve()
{
    vector<Contestant1> vec(101);

    string line;
    while (getline(cin, line) && !line.empty())
    {
        istringstream ss(line);
        int num, prob, time;
        char op;
        ss >> num >> prob >> time >> op;

        if (op == 'C')
        {
            if (vec[num].probCondi[prob] != 1)
            {
                vec[num].probCondi[prob] = 1;
                vec[num].ttime += time;
                vec[num].ttime += vec[num].triedBeforeAC[prob] * 20;
            }
        }           
        else
        {
            if (vec[num].probCondi[prob] != 1)
                vec[num].probCondi[prob] = -1;
            if (op == 'I')
                vec[num].triedBeforeAC[prob]++;
        }
    }

    vector<Contestant2> ans(101);

    for (int i = 1; i <= 100; i++)
        ans[i].id = i;
    
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (vec[i].probCondi[j] == 1)
                ans[i].solve++;
            if (vec[i].probCondi[j] != 0)
                ans[i].tried = true;
        }
            
        ans[i].ttime = vec[i].ttime;
    }

    sort(ans.begin(), ans.end(), cmp);

    for (auto &x : ans)
        if (x.tried)
            cout << x.id << ' ' << x.solve << ' ' << x.ttime << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    string trash;
    getline(cin, trash);

    for (int i = 0; i < t; i++)
    {
        if (i) cout << '\n';
        solve();
    }

    return 0;
}
//g++ -std=c++11 ".\10258－Contest Scoreboard.cpp" -o test.exe; Get-Content in.txt | .\test.exe