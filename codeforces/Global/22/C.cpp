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

int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    ll n = fast_IO::read();
    ll odd = 0;
    ll even = 0;
    for (int i = 1; i <= n; i++) {
      ll x;
      x = fast_IO::read();
      if (x & 1)
        odd++;
      else
        even++;
    }
    odd %= 4;
    even %= 2;
    if (odd == 1 && even == 0)
      puts("Bob");
    else if (odd == 2)
      puts("Bob");
    else
      puts("Alice");
  }

  return 0;
}
