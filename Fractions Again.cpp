//https://cn.vjudge.net/problem/UVA-10976
//简单枚举
//找出y枚举的范围(k, 2k]

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 5;


int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    while (scanf("%d", &k) != EOF) {
        int cnt = 0;
        queue<pair<int, int> > q;
        for (int y = k+1; y <= 2*k; y++) {
            if (k*y % (y-k) == 0) {
                q.push(make_pair(k*y/(y-k), y));
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            pair<int, int> p = q.front(); q.pop();
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
        }
    }

    return 0;
}