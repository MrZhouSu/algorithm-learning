#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

// namespace fast_IO
// {
//     ll read()
//     {
//         ll num = 0;
//         char c;
//         bool tag = false;
//         while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
//             ;
//         if (!~c)
//             return EOF;
//         if (c == '-')
//             tag = true;
//         else if (c == '+')
//             tag = false;
//         else
//             num = c ^ 48;
//         while ((c = getchar()) >= '0' && c <= '9')
//             num = (num << 1) + (num << 3) + (c ^ 48);
//         if (tag)
//             return -num;
//         return num;
//     }
//     void write(ll x)
//     {
//         if (x < 0)
//             putchar('-'), x = -x;
//         if (x >= 10)
//             write(x / 10);
//         putchar(x % 10 ^ 48);
//     }
// }
int n;

const int N = 110;

double eps = 1e-8;

double a[N][N];

int gauss()
{
    int r, c;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps)
            continue; //断开行自增

        swap(a[t], a[r]);

        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];

        r++;
    }

    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2;

        return 1;
    }

    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];

    return 0;
}

int main(void)
{
    system("chcp 65001");
    cout << "请输入方程数 : " << endl;
    scanf("%d", &n);
    cout << "请输入方程系数 : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    int t = gauss();

    if (t == 0)
        for (int i = 0; i < n; i++)
        {
            if (fabs(a[i][n]) < eps)
                a[i][n] = 0;
            printf("%.2f\n", a[i][n]);
        }
    else if (t == 1)
        puts("Infinite group solutions");
    else
        puts("No solution");

    system("pause");
    return 0;
}