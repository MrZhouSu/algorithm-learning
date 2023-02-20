
//并查集必须要有关系的传递才能归到一个集合，集合中任意两个元素是有关系的
// a==b b==c 那么 a==b==c 这个集合全部元素相等
// a!=b b!=c 不能推出a!=c 不等关系没有传递性 所以ac不能在一个集合

#include <iostream>
#include <algorithm>
#define ll long
using namespace std;

const ll N = 1e5 + 10;

ll p[N * 2];

ll q[N * 2];

struct point
{
    ll a, b, c;
} po[N];

ll n, line = 1;

ll find(ll x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

ll _Q(ll x)
{
    return lower_bound(q + 1, q + line + 1, x) - q;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;

    while (t--)
    {
        line = 1;

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            po[i] = {c, a, b};
            q[line++] = a;
            q[line++] = b;
        }

        sort(q + 1, q + line);

        line = unique(q + 1, q + line) - (q + 1);

        for (int i = 1; i <= line; i++)
            p[i] = i;

        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            if (po[i].a == 1)
            {
                p[find(_Q(po[i].b))] = find(_Q(po[i].c));
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (po[i].a == 0)
            {
                if (find(_Q(po[i].b)) == find(_Q(po[i].c)))
                {
                    // cout << po[i].b << " " << po[i].c << endl;
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}