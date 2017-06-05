//https://cn.vjudge.net/problem/UVA-11059
//简单枚举
//枚举起点与终点，注意long long
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 5;


int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, kase = 0;
    int s[99];
    while (scanf("%d", &n) != EOF) {
        long long maxone = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        for (int i = 0; i < n; i++) {
            long long submul = 1;
            for (int j = i; j < n; j++) {
                submul *= s[j];
                if (maxone < submul) maxone = submul;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++kase, maxone);
    }
    return 0;
}