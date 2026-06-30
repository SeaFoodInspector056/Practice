#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> qList(4);

void create_list()
{
    for (int i = 0; i < 10000; i++)
    {
        int qNum = i * i;
        int flag = 0;
        int digit = 10;

        while (flag < 4)
        {
            int temp = qNum / digit + qNum % digit;
            temp *= temp;

            if (temp == qNum && temp < digit *digit)
                qList[flag].push_back(temp);

            flag++;
            digit *= 10;
        }  
    }
}

void solve(int n)
{
    int flag = n / 2 - 1;
    for (int &x : qList[flag])
    {
        int digit = 1;
        if (x != 0)//0自動視為一位數
        {
            int temp = 1;
            while (x / temp != 0)
            {
                temp *= 10;
                digit++;
            }
            digit--;
        }
        
        for (int i = n; i > digit; i--)
            cout << '0';
        cout << x << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    create_list();

    int n;
    while (cin >> n)
        solve(n);

    return 0;
}
//g++ -std=c++11 ".\256 - Quirksome Squares.cpp" -o test.exe; Get-Content in.txt | .\test.exe