#include <bits/stdc++.h>
using namespace std;

void dfs (string s, int k, vector<int> &arr)
{
    int sign = 1;
    int num = 0;
    int n = s.size();
    int i = 1;
    char op;

    for (; i < n; i++)
        if(s[i] == '-')
            sign = -1;
        else if (isdigit(s[i]))
            num = num * 10 + (s[i] - '0');
        else 
        {
            op = s[i];
            break; 
        }
    
    num *= sign;
    
    if (op == '+')
    {
        dfs(s.substr(i + 1), k, arr);

        int prev = arr[0];//存原本的數
        arr[0] = num;
        for (int j = 1; j < k; j++)
        {
            int temp = arr[j];//存原本的數
            arr[j] = arr[j - 1] + prev;
            prev = temp;
        }
    }
    else if (op == '*')
    {
        dfs(s.substr(i + 1), k, arr);

        arr[0] = num * arr[0];
        for (int j = 1; j < k; j++)
            arr[j] = arr[j - 1] * arr[j];
    }
    else   
        fill(arr.begin(), arr.end(), num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    while (cin >> s >> n)
    {
        vector<int> arr(n);

        dfs(s, n, arr);

        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << arr[i];
        }
        cout << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\997 - Show the Sequence.cpp" -o test.exe; Get-Content in.txt | .\test.exe