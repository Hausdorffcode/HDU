//http://acm.hdu.edu.cn/showproblem.php?pid=1052
//贪心
//先排序，针对头尾讨论，变为子问题
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 1010;

int tian[MAXN];
int king[MAXN];

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &tian[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &king[i]);
        }
        sort(tian, tian+n, greater<int>());
        sort(king, king+n, greater<int>());
        int sum = 0;
        int l1, l2, r1, r2;
        l1=l2=0;
        r1=r2=n-1;
        while (l1 <= r1) {
            if (tian[l1] > king[l2]) {
                l1++;
                l2++;
                sum += 200;
            }
            else if (tian[l1] == king[l2] && tian[r1] > king[r2]) {
                r1--;
                r2--;
                sum += 200;
            }
            else {
                if (tian[r1] < king[l2]) sum -= 200;
                r1--;
                l2++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}