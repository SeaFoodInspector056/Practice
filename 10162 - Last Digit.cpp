#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    while (cin >> n && n != "0")//string比較只能用"" 已知每20次總和最後一位+4 每100次歸零
    {
        int size = n.size();

        int num;
        if (size < 2)
            num = n[size - 1] - '0';//記得要減字元!!!!!!!
        else 
            num = (n[size - 2] - '0') * 10 + (n[size - 1] - '0');
      
        int digit = num / 20 * 4;

        int sum = 0;
        for (int i = 1; i <= num % 20; i++)
        {
            int temp = 1;
            for (int j = 0; j < i; j++)
                temp = temp * i % 10;
            sum += temp;
        }       

        digit = (digit + sum) % 10;

        cout << digit << '\n';
    }

    return 0;
}
//g++ -std=c++11 "10162 - Last Digit.cpp" -o test.exe; Get-Content in.txt | .\test.exe