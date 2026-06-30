#include <bits/stdc++.h>
using namespace std;

vector<string> tokens;
int pos;

bool isOperator(string& s) 
{
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "%";//簡潔傳回true or false
}

bool isNumber(string& s) 
{
    for (char c : s)//s依序放進c判斷
        if (!isdigit(c)) return false;

    return true;
}

long long solve(bool& valid) 
{
    if (pos >= tokens.size()) 
    {
        valid = false;
        return 0;
    }

    string token = tokens[pos++];//pos先被呼叫再+1

    if (isNumber(token)) 
        return stoll(token);

    else if (isOperator(token)) 
    {
        long long left  = solve(valid);
        long long right = solve(valid);
        if (!valid) return 0;

        if ((token == "/" || token == "%") && right == 0) //分母不能為0!!
        {
            valid = false;
            return 0;
        }

        if (token == "+") return left + right;
        if (token == "-") return left - right;
        if (token == "*") return left * right;
        if (token == "/") return left / right;
        if (token == "%") return left % right;
    }

    valid = false;
    return 0;
}

int main() {
    string line;
    while (getline(cin, line)) 
    {
        if (line == ".") break;

        tokens.clear();
        pos = 0;

        istringstream ss(line);
        string token;
        while (ss >> token)
            tokens.push_back(token);//line轉成stream忽略空白依序放入tokens的nuits

        if (tokens.empty())//檢查是否空白
        {
            cout << "illegal\n";
            continue;
        }

        bool valid = true;
        long long result = solve(valid);

        // 用完所有 token 才算合法
        if (!valid or pos != tokens.size())
            cout << "illegal\n";
        else
            cout << result << "\n";
    }

    return 0;
}
//g++ -std=c++11 ".\2008-37Prefix expression evaluation.cpp" -o test.exe; Get-Content in.txt | .\test.exe