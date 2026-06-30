#include <bits/stdc++.h>

using namespace std;

struct Dir
{
    map<string, Dir> children;//map會照key自動排列，遞迴自己的目錄
};

void print(Dir& d, int depth)
{
    for (auto& p : d.children)// or map<string, Dir>::iterator it; for (i = d.children.begin(); i != d.children.end(); i++)
    {
        for (int i = 0; i < depth; i++) 
            cout << ' ';
        cout << p.first << '\n';
        print (p.second, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        Dir root;
        while (n--)
        {
            string s;
            cin >> s;

            Dir* cur = &root;//cur為指標取root的指標，作為一個會走路的指標邊指邊做節點

            stringstream ss(s);
            string part;
            while (getline(ss, part, '\\'))
                cur =  &(cur -> children[part]); //cur是指標!! 自動建立map樹狀 &優限度最低
        }

        print(root, 0);
        cout << '\n';
        string blank;
        getline(cin, blank);
    }
    return 0;
}