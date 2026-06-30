#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int t = 1;
    while(getline(cin, s))
    {
        int ans;
        vector<int> numList;
        vector<char> q;
        
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int n = 0;
                do
                {
                    n = n * 10 + s[i] - '0';
                    i++;
                } while (isdigit(s[i]));
                i--;
                
                numList.push_back(n);
            }
            else 
            {
                if (s[i] == '(')
                    if (flag == false)
                    {
                        flag = true;
                    }
                    else    
                    {
                        cout << "syntactically incorrect\n";
                        break;
                    }
                else if (s[i] == ')')
                    if (flag == true)
                    {
                        flag = false;
                    }
                    else
                    {
                        cout << "syntactically incorrect\n";
                        break;
                    }
                    
                    
                    



            }




        }






        cout << "case " << t << ":\n" << ans;
        t++;
    }

    return 0;
}