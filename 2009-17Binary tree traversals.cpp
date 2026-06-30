#include <bits/stdc++.h>
using namespace std;
//pre: root,  left,  right 
//in:  left,  root,  right 
//post:left,  right, root 
void postorder(char* pre, char* ino, int preL, int preR, int inoL, int inoR) 
{
    if (preL > preR) return;
 
    char root = pre[preL];
 
    // Find root in inorder
    int idx = inoL;
    while (ino[idx] != root) 
        idx++;
    int leftSize = idx - inoL;

    postorder(pre, ino, preL + 1, preL + 1 + (leftSize - 1), inoL, idx - 1);//左子樹
    postorder(pre, ino, preL + 1 + (leftSize - 1) + 1, preR, idx + 1, inoR);//右子樹

    cout << root << ' ';
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m; 
 
    while (m--) 
    {
        int n;
        cin >> n;
 
        char pre[n], ino[n];
 
        for (int i = 0; i < n; i++) 
            cin >> pre[i];
 
        for (int i = 0; i < n; i++) 
            cin >> ino[i];
 
        postorder(pre, ino, 0, n - 1, 0, n - 1);

        cout << "\n";
    }
 
    return 0;
}
//g++ -std=c++11 ".\2008-37Prefix expression evaluation.cpp" -o test.exe; Get-Content in.txt | .\test.exe