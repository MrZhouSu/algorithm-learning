#include <cstring>
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

int a[110];

int b[110];
int main(void) {
  int t = fast_IO::read();

  while (t--) {
    memset(b, 0, sizeof b);
    int n = fast_IO::read();

    int c = fast_IO::read();

    for (int i = 0; i < n; i++) {
      a[i] = fast_IO::read();

      b[a[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < 110; i++) {
      if (b[i] >= c)
        sum += c;
      else
        sum += b[i];
    }
    fast_IO::write(sum);
    puts("");
  }
  return 0;
}
