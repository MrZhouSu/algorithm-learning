#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
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

ll a[100010];
ll b[100010];
int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    ll n = fast_IO::read();

    for (ll i = 1; i <= n; i++) {
      a[i] = fast_IO::read();
    }

    if (n == 1)
      puts("YES");
    else {
      bool flag = true;
      b[1] = a[1];
      for (ll i = 2; i <= n; i++) {
        b[i] = lcm(a[i], a[i - 1]);
        if (gcd(b[i], b[i - 1]) != a[i - 1]) {
          puts("NO");
          flag = false;
          break;
        }
      }
      if (flag) {
        puts("YES");
      }
    }
  }
  return 0;
}
