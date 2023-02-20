#include <iostream>
#include <algorithm>
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 10;

int a[N];

PII b[N];

int main(void)
{
    int n, m, x, c, l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &c);
        b[i] = {x, c};
    }
    sort(b, b + n);
    a[0] = b[0].second;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i].second;
    }
    while (m--)
    {
        scanf("%d%d", &l, &r);
        if (b[n - 1].first < l || b[0].first > r)
        {
            cout << 0 << endl;
            continue;
        }
        int i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + j >> 1;
            if (b[mid].first >= l)
                j = mid;
            else
                i = mid + 1;
        }
        int o = i;
        i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + j + 1 >> 1;
            if (b[mid].first <= r)
                i = mid;
            else
                j = mid - 1;
        }
        int p = i;
        if (o > p)
        {
            cout << 0 << endl;
            continue;
        }
        cout << a[p] - a[o] + b[o].second << endl;
    }
    return 0;
}