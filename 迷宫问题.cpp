//https://cn.vjudge.net/problem/POJ-3984
//bfs
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int MAXN = 5;

int maze[25];
bool vis[25];
int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int father[25];


bool isValid(int x, int y) {
    return x >= 0 && x <5 && y >=0 && y < 5;
}

void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        //printf("(%d, %d)\n", t/5, t%5);
        int x = t/5;
        int y = t%5;
        if (isValid(x, y-1) && vis[t-1] == false) {vis[t-1] = true; q.push(t-1); father[t-1] = t;}
        if (isValid(x, y+1) && vis[t+1] == false) {vis[t+1] = true; q.push(t+1); father[t+1] = t;}
        if (isValid(x-1, y) && vis[t-5] == false) {vis[t-5] = true; q.push(t-5); father[t-5] = t;}
        if (isValid(x+1, y) && vis[t+5] == false) {vis[t+5] = true; q.push(t+5); father[t+5] = t;}
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i*5+j];
            if (maze[i*5+j] == 1) vis[i*5+j] = true;
        }
    }
    bfs(0);
    stack<int> s;
    for(int i = 24; i > 0;){
        s.push(i);
        i = father[i];
    }
    printf("(0, 0)\n");
    while (!s.empty()) {
        int temp = s.top(); s.pop();
        printf("(%d, %d)\n", temp/5, temp%5);
    }
    return 0;
}