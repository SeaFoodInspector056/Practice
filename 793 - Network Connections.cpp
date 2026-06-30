#include <bits/stdc++.h>
using namespace std;
//parent代表root rnk代表這個節點的高度
vector<int> parent, rnk;

//找根
int find_root(int x)
{
    if (parent[x] != x)
        parent[x] = find_root(parent[x]);//沿途路徑壓縮至根
    return parent[x];
}

//把電腦相連(樹相連) a當根
void unite(int a, int b)
{
    int aRoot = find_root(a), bRoot = find_root(b);//誰當根順序任意 只看誰是a誰當根

    //如果同根則忽略
    if (aRoot == bRoot) return;

    //把矮的樹接到高的樹下面 我們只在意是否在同一棵樹 所以把矮樹的根直接接到高樹的根也沒關係(任意接都沒關係 但這樣可以防止樹太高 遞迴太久) 
    //而對高樹而言 矮樹不會超過高樹的高度 因此接上去不會影響整個樹的高度(除非同高)
    if (rnk[aRoot] < rnk[bRoot]) swap(aRoot, bRoot);//預設aRoot為高的樹
    else if (rnk[aRoot] == rnk[bRoot]) rnk[aRoot]++;//同高
    parent[bRoot] = aRoot;//把矮樹的根設為兩樹的接點
}

void solve()
{
    int n;
    cin >> n;
    cin.ignore();

    parent.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;//預設自己的根是自己

    int suc = 0, unsuc = 0;

    string line;
    while (getline(cin,line) && !line.empty())
    {
        istringstream ss(line);
        char op;
        int a, b;
        ss >> op >> a >> b;

        if (op == 'c')
            unite(a, b);
        else if (op == 'q')
        {
            if (find_root(a) == find_root(b))//如果同根代表有相連
                suc++;
            else   
                unsuc++;
        }
    }

    cout << suc << ',' << unsuc  << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        if (i)  cout << '\n';
        solve();
    }
    return 0;
}