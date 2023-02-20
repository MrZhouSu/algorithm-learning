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

const int N = 2e5 + 10;

ll a[N];

int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    ll n = fast_IO::read();
    ll sum = n;
    for (ll i = 1; i <= n; i++) {
      a[i] = fast_IO::read();
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      for (ll j = i + ans + 1; j <= n; j++) {
        if (a[j] >= j - i + 1)
          ans++;
        else
          break;
      }
      sum += ans;
      ans--;
    }
    printf("%lld\n", sum);
  }
}
