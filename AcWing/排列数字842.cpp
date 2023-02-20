//排列数
#include <iostream>

using namespace std;

const int N = 7;

int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            path[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main(void)
{
    cin >> n;
    dfs(0);
    system("pause");
    return 0;
}