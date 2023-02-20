#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define PLL pair<ll, ll>
const int N = 4e5 + 10;

namespace fast_IO
{
    ll read()
    {
        ll num = 0;
        char c;
        bool tag = false;
        while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
            ;
        if (!~c)
            return EOF;
        if (c == '-')
            tag = true;
        else if (c == '+')
            tag = false;
        else
            num = c ^ 48;
        while ((c = getchar()) >= '0' && c <= '9')
            num = (num << 1) + (num << 3) + (c ^ 48);
        if (tag)
            return -num;
        return num;
    }
    void write(ll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x >= 10)
            write(x / 10);
        putchar(x % 10 ^ 48);
    }
}

PLL a[N];

ll sum[N];

int main(void)
{
    ll n = fast_IO::read();

    for (int i = 0; i < 2 * n; i += 2)
    {
        a[i].first = fast_IO::read();

        a[i + 1].first = fast_IO::read();

        a[i + 1].first++;

        a[i].second++;

        a[i + 1].second--;
    }

    sort(a, a + 2 * n);

    ll l = a[0].first;

    ll ans = 0;

    // for(int i=0;i<2*n;i++)
    // {
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }

    for (int i = 0; i < 2 * n; i++)
    {
        ans += a[i].second;

        if (l != a[i].first)
        {
            sum[ans - a[i].second] += a[i].first - l;

            // cout<<ans-a[i].second<<" "<<sum[ans-a[i].second]<<endl;

            // ans+=a[i].second;

            l = a[i].first;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        fast_IO::write(sum[i]);
        putchar(' ');
    }
    system("pause");
    return 0;
}
