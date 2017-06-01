//http://acm.hdu.edu.cn/showproblem.php?pid=2899
//区间内不单调，但是满足凸性（导函数单增），极值点导函数为0，二分导函数
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 3010;

double df(double x) {
    return 42*pow(x, 6) + 48*pow(x, 5) + 21*pow(x, 2) + 10*x;
}

double f(double x, double y) {
    return 6*pow(x, 7) + 8*pow(x, 6) + 7*pow(x, 3) + 5*pow(x, 2) - y*x;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        double y;
        scanf("%lf", &y);
        if (y < 0 || y > df(100)) {
            printf("%.4lf\n", min(f(0, y), f(100, y)));
            continue;
        }
        double lo, hi, mid;
        lo = 0;
        hi = 100;
        while (hi - lo > eps) {
            mid = lo + (hi-lo) / 2;
            double ans = df(mid);
            if (ans > y) {
                hi = mid - 1e-7;
            }
            else {
                lo = mid + 1e-7;
            }
        }
        printf("%.4lf\n", f(mid, y));
    }
    return 0;
}