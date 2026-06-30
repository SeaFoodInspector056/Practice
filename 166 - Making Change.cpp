#include <bits/stdc++.h>
using namespace std;

int MAX_VALUE = 700;
int INF = 1e6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int coin[6] = {5, 10, 20, 50, 100, 200};

    //處理店家找零金額的完全背包
    vector<int> dpShop(MAX_VALUE, INF);//紀錄最少需要多少枚
    dpShop[0] = 0;
    for (int i = 0; i < 6; i++)//遍歷每一種面額
        for (int j = coin[i]; j < MAX_VALUE; j++)//從該面額開始更新到最大值
            dpShop[j] = min(dpShop[j], dpShop[j - coin[i]] + 1);

    while (true)
    {
        bool flag = true;
        int have[6];
        for (int i = 0; i < 6; i++)
        {
            cin >> have[i];
            if (have[i] != 0)
                flag = false;
        }
        if (flag) break;

        double price;
        cin >> price;
        int target = static_cast<int>(round(price * 100));//記得round()!!!!!!

        //處理買家的多重背包
        vector<int> dpBuyer(MAX_VALUE, INF);
        dpBuyer[0] = 0;
        for (int i = 0 ; i < 6; i++)//遍歷每一種面額
            for (int j = 0; j < have[i]; j++)//遍歷該面額的數量0到全部
                for (int k = MAX_VALUE - 1; k >= coin[i]; k--)//從最大值500開始更新到該面額
                    dpBuyer[k] = min(dpBuyer[k], dpBuyer[k - coin[i]] + 1);

        //找最小交換數
        int minEx = INF;
        for (int i = target; i < MAX_VALUE; i++)
            minEx = min(minEx, dpBuyer[i] + dpShop[i - target]);

        cout << setw(3) << minEx << '\n';
    }

    return 0;
}
//g++ -std=c++11 ".\166 - Making Change.cpp" -o test.exe; Get-Content in.txt | .\test.exe