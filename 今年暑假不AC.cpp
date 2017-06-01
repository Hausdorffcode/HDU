//http://acm.hdu.edu.cn/showproblem.php?pid=2037
//贪心
//选择不相交区间
//sort，与结构体的用法
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
const int MAXN = 110;

struct node {
    int beginT;
    int endT;
};

bool mycmp(node a, node b) {
    return a.endT < b.endT;
}

node jiemu[MAXN];

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &jiemu[i].beginT, &jiemu[i].endT);
        }

        sort(jiemu, jiemu+n, mycmp);

        int cnt = 1;
        int r = jiemu[0].endT;
        for (int i = 1; i < n; i++) {
            if (jiemu[i].beginT >= r) {
                cnt++;
                r = jiemu[i].endT;
                //printf("r=%d\n", r);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}