#include <bits/stdc++.h>
using namespace std;

int arr[9][9]; 

//回傳第一個找到的0
pair<int, int> isEmpty()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (arr[i][j] == 0)
                return {i, j};
    
    return {-1, -1};
}

//檢驗是否合法
bool check(int x, int y, int num)
{
    for (int k = 0; k < 9; k++)
        if (arr[x][k] == num or arr[k][y] == num)
            return false;

    int row = x - x % 3;
    int col = y - y % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[row + i][col + j] == num)
                return false;
                
    return true;
}

//回朔法主體
bool backing()
{
    pair<int, int> pos = isEmpty();
    int x = pos.first;
    int y = pos.second;

    if (x == -1 and y == -1)
        return true;

    for (int num = 1; num < 10; num++)
        if (check(x, y, num))
        {
            arr[x][y] = num;
            if (backing())//直到找不到0
                return true;
            else 
                arr[x][y] = 0;//找不到答案就回朔成0
        }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        //輸入sudoku
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> arr[i][j];

        //回朔法找答案
        if (backing())
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j)
                        cout << ' ';
                    cout << arr[i][j];
                }
                cout << '\n';
            }  
        else
            cout << "NO\n";
    }

    return 0;
}