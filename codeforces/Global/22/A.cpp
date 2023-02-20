#include <algorithm>
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
#define PII pair<ll, ll>

const int N = 1e5 + 10;

ll a[N];

ll b[N];

ll c[N];

bool cmp(ll &a, ll &b) { return a > b; }

int main(void) {
  ll t = fast_IO::read();
  while (t--) {
    ll line1 = 1, line2 = 1;
    ll n = fast_IO::read();

    for (int i = 1; i <= n; i++) {
      a[i] = fast_IO::read();
    }
    for (int i = 1; i <= n; i++) {
      ll s = fast_IO::read();
      if (a[i]) {
        b[line1++] = s;
      } else {
        c[line2++] = s;
      }
    }

    sort(b + 1, b + line1, cmp);
    sort(c + 1, c + line2, cmp);

    ll sum = 0;

    bool flag = true;

    if (line1 > line2) {
      sum += b[line1 - 1];
      line1--;
    } else if (line1 < line2) {
      sum += c[line2 - 1];
      line2--;
      flag = false;
    } else {
      if (b[line1 - 1] < c[line2 - 1]) {
        sum += b[line1 - 1];
        line1--;
      } else {
        sum += c[line2 - 1];
        line2--;
        flag = false;
      }
    }
    // cout << "sb" << endl;
    // cout << line1 << endl;
    // cout << line2 << endl;
    // cout << sum << endl;
    for (int i = 1; i < min(line1, line2); i++) {
      sum += 2 * b[i];
      sum += 2 * c[i];
    }

    if (line1 > line2) {
      for (int i = line2; i < line1; i++) {
        if (i == line2 && !flag)
          sum += 2 * b[i];
        else
          sum += b[i];
      }
    } else {
      for (int i = line1; i < line2; i++) {
        if (i == line1 && flag)
          sum += 2 * c[i];
        else
          sum += c[i];
      }
    }
    printf("%lld\n", sum);
  }

  return 0;
}
