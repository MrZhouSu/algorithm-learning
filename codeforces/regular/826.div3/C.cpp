#include <iostream>
using namespace std;
#define ll long long
namespace fast_IO {
ll read() {
  ll num = 0;
  char c;
  bool tag = false;
  while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
    ;
  if (!~c) return EOF;
  if (c == '-')
    tag = true;
  else if (c == '+')
    tag = false;
  else
    num = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    num = (num << 1) + (num << 3) + (c ^ 48);
  if (tag) return -num;
  return num;
}
void write(ll x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace fast_IO

ll a[2010];

ll n;

bool check(ll mid, ll &maxid) {
  ll ans = 0;
  ll j = 1;
  for (ll i = 1; i <= n; i++) {
    ans += a[i];
    if (ans == mid) {
      ans = 0;
      maxid = max(maxid, i - j + 1);
      j = i + 1;
    } else if (ans > mid) {
      return false;
    }
  }
  if (ans != 0 && ans != mid) return false;
  return true;
}
int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    ll maxid = 1e9;
    n = fast_IO::read();
    ll sum = 0;
    ll minid = 1e7;
    for (ll i = 1; i <= n; i++) {
      a[i] = fast_IO::read();
    }
    ll ma = 0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      ans += a[i];
      ma = 0;
      if (check(ans, ma)) {
        // cout << i << endl;
        maxid = min(maxid, ma);
      }
    }
    cout << maxid << endl;
  }
  return 0;
}
