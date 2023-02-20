// 8皇后问题
#include <iostream>

#include <cstring>

using namespace std;

const int N = 20;

bool col[N], dg[N], udg[N];

char g[N][N];

int n;

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            col[i] = dg[u + i] = udg[n - u + i] = true;
            g[u][i] = 'Q';
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0);
    system("pause");
    return 0;
}