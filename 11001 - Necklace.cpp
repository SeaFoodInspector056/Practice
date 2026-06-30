#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vt, v0;
    while (cin >> vt >> v0 && vt != 0 && v0 != 0)
    {
        double n = 1.0 * vt / (2 * v0);//轉成浮點數除法
        int nn = n;
        if (vt / round(n) <= v0)
            cout << "0\n";//要用""
        else if (n - nn == 0.5)//頂點在兩個整數之間，答案不唯一因此為0
            cout << "0\n";
        else if (n - nn < 0.5)
            cout << nn << '\n';
        else 
            cout << nn + 1 << '\n';
    }

    return 0;
}
