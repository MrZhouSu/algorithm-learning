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
const double eps = 1e-8;
int main(void) {
  ll t;
  scanf("%lld", &t);

  while (t--) {
    unsigned ll sum = 0;
    ll l, r;
    scanf("%lld%lld", &l, &r);

    ll k = sqrt(l), p = sqrt(r);

    while (k * k < l) k++;
    while (p * p < r) p++;

    if (k * k != l) {
      for (unsigned ll i = (k - 1) * (k); i < k * k;
           i += (k - 1))  // 计算 l到k方之间
      {
        if (i >= l) sum++;
      }
    }
    if (p * p != r) {
      p--;
      for (unsigned ll i = p * p + p; i <= r; i += p) {
        sum++;
      }
    }

    sum += (p - k + 1) + 2 * (p - k);
    printf("%lld\n", sum);
  }
  return 0;
}
