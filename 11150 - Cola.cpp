#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {

        int full = n, drank = 0, empty = 0;

        while (full > 0)
        {
            drank += full;
            empty += full;
            full = empty / 3;
            empty -= empty / 3 * 3;
        }
        
        if (empty % 3 == 2)
            drank++; 
        
        cout << drank << '\n';
    }

    return 0;
}