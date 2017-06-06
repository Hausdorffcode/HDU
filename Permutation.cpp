//生成[1, n]的全排列
void print_permutation(int n, int* A, int cur) {
    //printf("%d\n", cur);
    if (cur == n) {
        for (int i= 0; i < cur; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            for (int j = 0; j < cur; j++) {
                if (A[j] == i) { ok = false; break; }
            }
            if (ok) { A[cur] = i; print_permutation(n, A, cur+1); }
        }
    }
}

//生成可重集的排序
//P要求以排序
void print_permutation(int n, int* A, int cur, int* P) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!i || P[i] != P[i-1]) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++) if (P[j] == P[i]) c2++;
                for (int k = 0; k < cur; k++) if (A[k] == P[i]) c1++;
                if (c1 < c2) {
                    A[cur] = P[i];
                    print_permutation(n, A, cur+1, P);
                }
            }
        }
    }
}

//使用STL，同样使用可重集
int main()
{
    int n, p[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    sort(p, p+n);
    do {
        for (int i = 0; i < n; i++) printf("%d ", p[i]);
        printf("\n");
    } while (next_permutation(p, p+n));
    return 0;
}