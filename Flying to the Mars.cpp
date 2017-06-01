//http://acm.hdu.edu.cn/showproblem.php?pid=1800
//贪心
//就是每次抽取最长严格增序列，可以抽几次，于是题目就是求重复数字最多的个数
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
const int MAXN = 3010;

int level[MAXN];

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &level[i]);
        }
        sort(level, level+n);
        int cnt = 1;
        int cm = level[0];
        int ccnt = 1;
        for (int i = 1; i < n; i++) {
            if (level[i] == cm) ccnt++;
            else {
                ccnt = 1;
                cm = level[i];
            }
            if (ccnt > cnt) cnt = ccnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}