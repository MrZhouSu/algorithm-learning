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
ll n, m;
bool check(int i, int j) {
  if (i + 2 <= n && j + 1 <= m) return false;
  if (i + 1 <= n && j + 2 <= m) return false;
  if (i + 2 <= n && j - i >= 1) return false;
  if (i + 2 <= n && j - 2 >= 1) return false;
  if (i - 2 >= 1 && j - 1 >= 1) return false;
  if (i - 1 >= 1 && j - 2 >= 1) return false;
  if (i - 2 >= 1 && j + 1 <= m) return false;
  if (i - 1 >= 1 && j + 2 <= m) return false;
  return true;
}

int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    n = fast_IO::read();
    m = fast_IO::read();

    bool flag = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (check(i, j)) {
          printf("%d %d", i, j);
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) printf("%d %d", n, m);
    puts("");
  }
  return 0;
}
