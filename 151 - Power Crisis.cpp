#include <iostream>

using namespace std;

int main ()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0) break;

        int m = 1;

        while (true)
        {
            int pt = 0;
            for (int i = 2; i < n ; i++)
                pt = (pt + m) % i;//用最後一個黑來反推原本的位置和m                                   
            
            if (pt == 11)                                             
            {
                cout << m << '\n'; 
                break;
            }

            m++;

        }
    }

    return 0;    
}