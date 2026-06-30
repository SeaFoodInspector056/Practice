#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double PI = 3.141592653589793;
    double x1, y1, x2, y2, x3, y3;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double a1 = x2 - x1, b1 = y2 - y1;
        double c1 = (x2*x2 - x1*x1 + y2*y2 - y1*y1) / 2.0;

        double a2 = x3 - x2, b2 = y3 - y2;
        double c2 = (x3*x3 - x2*x2 + y3*y3 - y2*y2) / 2.0;

        double det = a1*b2 - a2*b1;
        double cx = (c1*b2 - c2*b1) / det;
        double cy = (a1*c2 - a2*c1) / det;

        // 半徑
        double r = sqrt((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1));

        cout << fixed << setprecision(2) << 2 * PI * r << '\n';
    }

    return 0;
}