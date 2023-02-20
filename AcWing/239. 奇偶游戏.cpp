#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

const int N = 5010;

ll n, m, tot = 1;

ll _Q(ll x)
{
    return lower_bound(q + 1, q + tot + 1, x) - q;
}

ll p[N * 2], q[N * 2], d[N * 2];

ll find(ll x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

struct point
{
    ll l, r;
    string ch;
} po[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    string ch;

    for (int i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b >> ch;

        po[i] = {a, b + 1};

        q[tot++] = a;
        q[tot++] = b + 1;
    }

    sort(q + 1, q + tot);

    tot = unique(q + 1, q + tot) - (q + 1);

    for (int i = 1; i <= tot; i++)
    {
        p[i] = i;
    }
    bool flag = true;

    for (int i = 1; i <= m; i++)
    {
        ll l = _Q(po[i].l);
        ll r = _Q(po[i].r);
        string ch = po[i].ch;

        ll pl = find(l);
        ll pr = find(r);

        if (pl == pr)
        {
            if (d[pl] == 0 && ch != "even" || d[pl] == 1 && ch != "odd")
            {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        else
        {
            p[pl] = pr;
            d[pr] = ch == "even" ? 0 : 1;
        }
    }

    if (flag)
        cout << m << endl;
    return 0;
}