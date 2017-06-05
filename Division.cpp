//https://cn.vjudge.net/problem/UVA-725
//简单枚举
//只要枚举fghij，并且所有的数加起来超过10位时就可以终止枚举了
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 5;

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, kase = 0;
    char num[99];
    while (scanf("%d", &n) == 1 && n) {
        int cnt = 0;
        if (kase++) printf("\n");
        for (int i = 1234; ; i++) {
            int j = i * n;
            sprintf(num, "%05d%05d", i, j);
            if (strlen(num) > 10) break;
            sort(num, num+10);
            bool flag = true;
            for (int k = 0; k < 10; k++) {
                if (num[k] != k + '0') {
                    flag = false;
                    break;
                }
            }
            if (flag) {printf("%05d / %05d = %d\n", j, i, n); cnt++;}
        }
        if (!cnt) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}