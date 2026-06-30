#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        getline(cin, a, ':');
        getline(cin, b);
        int hr = stoi(a);
        int min = stoi(b);

        auto print = [&]()
        {
            a = to_string(hr);
            b = to_string(min);
            cout << setw(2) << setfill('0') << a << ':' << setw(2) << setfill('0') << b << '\n';
        };

        while (true)
        {
            min++;
            if (min >= 60)
            {
                min -= 60;
                hr++;
            }

            if (hr >= 24)
            {
                hr-= 24;
            }

            if (hr / 10 != 0)
            {
                if (hr / 10 == min % 10 && hr % 10 == min / 10)
                {
                    print();
                    break;
                }
            }
            else if (hr % 10 != 0)
            {
                if (hr % 10 == min % 10) 
                {
                    print();
                    break;
                }
            }
            else if (min / 10 != 0) 
            {
                if (min / 10 == min % 10)
                {
                    print();
                    break;
                }
            }
            else 
            {
                print();
                break;
            }
        }
    }

    return 0;
}
//g++ -std=c++11 ".\11309 - Counting Chaos.cpp" -o test.exe; Get-Content in.txt | .\test.exe    