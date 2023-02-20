#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], q[N], hh, tt = -1, n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k == q[hh])
            hh++;

        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }

    cout << endl;

    tt = -1, hh = 0;

    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k == q[hh])
            hh++;

        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }
    system("pause");
    return 0;
}