//生成-测试法
//tot=92, cnt = 19173961
int c[50], tot = 0, cnt = 0, n = 8;

void queue_search (int cur) {
    cnt++;
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (c[i] == c[j] || c[i] - i == c[j] - j || c[i] + i == c[j] + j)
                    return;
            }
        }
        tot++;
        return;
    }
    for (int i = 0; i < n; i++) {
        c[cur] = i;
        queue_search(cur+1);
    }
}

int main()
{
    queue_search(0);
    printf("tot = %d\ncnt = %d\n", tot, cnt);
    return 0;
}

//普通回溯法
//tot=92, cnt = 2057
int c[50], tot = 0, cnt = 0, n = 8;

void queue_search(int cur) {
    cnt++;
    if (cur == n) { tot++; return; }
    for (int i = 0; i < n; i++) {
        c[cur] = i;
        bool ok=true;
        for (int j = 0; j < cur; j++) {
            if (c[cur] == c[j] || cur-c[cur] == j-c[j] || cur+c[cur] == j+c[j]) {
                ok = false;
                break;
            }
        }
        if (ok) queue_search(cur+1);
    }
}

//优化的回溯法
//tot = 92, cnt = 2057
int c[50], tot = 0, cnt = 0, n = 8, vis[3][50];

void queue_search(int cur) {
    cnt++;
    if (cur == n) { tot++; return; }
    for (int i = 0; i < n; i++) {
        if (!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
            c[cur] = i;
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
            queue_search(cur+1);
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    queue_search(0);
    printf("tot = %d\ncnt = %d\n", tot, cnt);
    return 0;
}