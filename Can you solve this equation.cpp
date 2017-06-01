//http://acm.hdu.edu.cn/showproblem.php?pid=2199
//区间内满足单调性，直接二分
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 3010;

double f(double x) {
    return 8*pow(x, 4) + 7*pow(x, 3) + 2*pow(x, 2) + 3*x + 6;
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
        if (y < 6 || y > f(100)) {
            printf("No solution!\n");
            continue;
        }
        double lo, hi, mid;
        lo = 0;
        hi = 100;
        while (hi - lo > eps) {
            mid = lo + (hi-lo) / 2;
            double ans = f(mid);
            if (ans > y) {
                hi = mid - 1e-7;
            }
            else {
                lo = mid + 1e-7;
            }
            //printf("%.4lf\n", mid);
        }
        printf("%.4lf\n", mid);
    }
    return 0;
}