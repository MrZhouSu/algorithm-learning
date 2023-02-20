#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int a[N][N];

int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c)
{
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main(void)
{
    int x;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            insert(i, j, i, j, x);
        }
    }
    int x1, y1, x2, y2, c;
    while (q--)
    {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}