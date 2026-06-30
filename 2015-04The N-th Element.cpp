#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve()
{
    int p, q, r;
    int x, y, z;
    int n;
    cin >> p >> q >> r;
    cin >> x >> y >> z;
    cin >> n;

    auto A = [&](ll i) {return p*i*i + q*i + r;};
    auto B = [&](ll i) {return x*i*i + y*i + z;};

    //在A陣列找比val小於等於的數量 (->指定型別) 
    auto cntA = [&](ll val) -> ll
    {
        if (A(0) > val) return 0;//如果比A最小的還要小就代表不在A裡面

        ll lo = 0, hi = n - 1, res;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (A(mid) <= val)
            {
                res = mid + 1;//索引值從0開始 故有mid + 1個人符合條件
                lo = mid + 1;//找mid的右邊是否有人也符合小於等於val(左邊和mid都符合條件了)
            }
            else hi = mid - 1;//找mid的左邊(mid和右邊都不符合條件)
        }

        return res;
    };

    auto cntB = [&](ll val) -> ll
    {
        if (B(0) > val) return 0;

        ll lo = 0, hi = n - 1, res;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (B(mid) <= val)
            {
                res = mid + 1;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return res;
    };

    ll lo = min(A(0), B(0));
    ll hi = max(A(n - 1), B(n - 1));
    ll ans = hi;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;//mid = (lo + hi) / 2 可能溢位
        if (cntA(mid) + cntB(mid) >= n)//小於等於mid的元素數量大於等於第n位元素(第n元素即前面有n個元素小於等於)
        {//即mid有可能太大或剛好等於第n位元素 (mid有資格為第n元素)
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;//代表比mid小的數字加上mid都不到n個 無法構成mid為第n元素
    }

    return ans;
}//每個部分都binary search

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    while (m--)
        cout << solve() << '\n';

    return 0;
}