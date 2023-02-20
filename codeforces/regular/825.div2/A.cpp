#include <cmath>
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
ll a[110];
ll b[110];
int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    ll sum = 0;
    ll a1 = 0;
    ll b1 = 0;
    ll n = fast_IO::read();

    for (ll i = 0; i < n; i++) {
      a[i] = fast_IO::read();
      if (a[i] == 1) a1++;
    }

    for (ll i = 0; i < n; i++) {
      b[i] = fast_IO::read();
      if (b[i] == 1) b1++;
      if (a[i] == b[i]) sum++;
    }

    fast_IO::write(abs(a1 - b1) + (n - sum - abs(a1 - b1) != 0));
    puts("");
  }
  return 0;
}
