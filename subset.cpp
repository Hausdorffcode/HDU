// {0~n-1}的所有子集：增量构造法
//一次选出一个元素放到集合中
void print_subset(int n, int* A, int cur) {
    for (int i = 0; i < cur; i++) printf("%d ", A[i]);
    printf("\n");
    int s = cur ? A[cur-1]+1 : 0;
    for (int i = s; i < n; i++) {
        A[cur] = i;
        print_subset(n, A, cur+1);
    }
}


//{0~n-1}的所有子集 构造位向量B[i]，位向量法
void print_subset(int n, int* B, int cur) {
    if (cur == n) {
        for (int i = 0; i < cur; i++) {
            if (B[i]) printf("%d ", i);
        }
        printf("\n");
        return;
    }
    B[cur] = 1;
    print_subset(n, B, cur+1);
    B[cur] = 0;
    print_subset(n, B, cur+1);
}

//{0~n-1}的所有子集 二进制法
