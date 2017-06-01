//http://acm.hdu.edu.cn/showproblem.php?pid=1050
//贪心
//将每次搬运连成一条线，记录最大重叠
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
const int MAXN = 200;

int cnt[MAXN];

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; i++) {
            int s, t;
            scanf("%d %d", &s, &t);
            int l = (s-1)/2;
            int r = (t-1)/2;
            if (l > r) {
                int temp = l;
                l = r;
                r = temp;
            }
            //printf("l=%d  r=%d\n", l, r);

            for (int j = l; j <= r; j++) {
                cnt[j]++;
            }
        }
        int maxt = cnt[0];
        for (int i = 1; i < MAXN; i++) {
            if (maxt < cnt[i])
                maxt = cnt[i];
        }
        printf("%d\n", maxt*10);
    }
    return 0;
}
