#include <iostream>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int arr[n], hi = 0, lo = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            hi += arr[i];//全塞入同一個
            lo = max(lo, arr[i]);//個別單一最大 
        }

        while (lo < hi)
        {
            int mid = (lo + hi) / 2, count = 1, sum = 0;//mid猜的答案 count現在裝的容器 sum這個容器裝的多少
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > mid) break;

                if (sum + arr[i] > mid)
                {
                    count++; 
                    sum = arr[i];
                }
                else
                {
                    sum += arr[i];
                }
            }

            if (count <= m)
                hi = mid;
            else 
                lo = mid + 1;
        }
        
        cout << lo << '\n';
    }

    return 0;
}