#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n && n != 0)
    {
        int top = 1;
        int north = 2;
        int west = 3;
        while (n--)
        {
            string s;
            cin >> s;

            int tempTop = top;
            int tempNorth = north;
            int tempWest = west;
            if (s == "north")
            {
                top = 7 - tempNorth;
                north = tempTop;
            }
            else if (s == "east")
            {
                top = tempWest;
                west = 7 - tempTop;
            }
            else if (s == "west")
            {
                top = 7 - tempWest;
                west = tempTop;
            }
            else if (s == "south")
            {
                top = tempNorth;
                north = 7 - tempTop;
            }
        }

        cout << top << '\n';
    }

    return 0;
}
//++ -std=c++11 ".\10409 - Die Game.cpp" -o test.exe; Get-Content in.txt | .\test.exe