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

ll n;

const int N = 1e5 + 10;

int a[N], b[N];

double ans;

bool check(double mid) {
  double maxid = -2e8, minid = 2e8;

  for (int i = 0; i < n; i++) {
    if (mid < b[i]) return false;
    minid = min(minid, a[i] + mid - b[i]);
    maxid = max(maxid, a[i] - (mid - b[i]));
  }
  ans = maxid;
  return minid >= maxid;
}

int main(void) {
  ll t = fast_IO::read();

  while (t--) {
    n = fast_IO::read();

    double i = 0, j = 2e8;

    for (int i = 0; i < n; i++) {
      a[i] = fast_IO::read();
    }

    for (int i = 0; i < n; i++) {
      b[i] = fast_IO::read();
    }

    for (int k = 1; k <= 100; k++) {
      double mid = (i + j) / 2;
      if (check(mid))
        j = mid;
      else
        i = mid;
    }

    // check(j);

    printf("%.10f\n", ans);
  }

  return 0;
}
