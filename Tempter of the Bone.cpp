//http://acm.hdu.edu.cn/showproblem.php?pid=1010
//dfs
//奇偶剪枝
//此题测试数据空格有问题，建议用cin
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

char maze[9][9];
int N,M,T,ei,ej, si, sj;
bool esc;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};


void dfs(int i, int j, int cnt) {
    //printf("i = %d    j = %d\n", i, j);
    if (i >= N || i < 0 || j >= M || j < 0) return;
    if (i == ei &&j == ej && cnt == T) {esc = true; return;}

    //剪枝
    if (esc) return;
    int temp = T-cnt -abs(ei-i) - abs(ej-j);
    if (temp < 0 || temp & 1) return;  //奇偶剪枝

    for (int k = 0; k < 4; k++) {
        if (maze[i+dir[k][0]][j+dir[k][1]] != 'X') {
            maze[i+dir[k][0]][j+dir[k][1]] = 'X';
            dfs(i+dir[k][0], j+dir[k][1], cnt+1);
            maze[i+dir[k][0]][j+dir[k][1]] = '.';
        }
    }
    return;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin>>N>>M>>T && (T || N || M))
    {
      int wall=0;
      for(int i=0;i<N;i++)
         for(int j=0;j<M;j++)
         {
            cin>>maze[i][j];
            if(maze[i][j]=='S') { si=i; sj=j; }
            else if(maze[i][j]=='D') { ei=i; ej=j; }
            else if(maze[i][j]=='X') wall++;
         }
		 
		//剪枝
       if(N*M-wall<=T)
       {
           cout<<"NO"<<endl;
           continue;
       }
	   
       esc=false;
       maze[si][sj]='X';
       dfs(si,sj,0);
       if(esc) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }

    return 0;
}