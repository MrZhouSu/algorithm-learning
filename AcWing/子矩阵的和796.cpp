#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int a[N][N];

int pre[N][N];
int n, m, q;
void presum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
}
int main(void)
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    presum();
    int x1, x2, y1, y2;
    while (q--)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cout << pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] << endl;
    }
    // cout << "周";
    // system("pause");
    return 0;
}