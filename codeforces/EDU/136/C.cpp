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
const int MOD = 998244353;

const int N = 105;

ll C[N][N];

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j] % MOD + C[i - 1][j - 1] % MOD) % MOD;
    }
  }
}

PII f[N];

int main(void) {
  init();

  f[2].first = 1;
  f[2].second = 0;

  for (int i = 4; i <= 60; i += 2) {
    f[i].first = (C[i - 1][i / 2 - 1] % MOD + f[i - 2].second % MOD) % MOD;
    f[i].second = (C[i][i / 2] - f[i].first - 1 + MOD) % MOD;
  }

  ll t = fast_IO::read();
  while (t--) {
    ll n = fast_IO::read();

    printf("%lld %lld 1\n", f[n].first, f[n].second);
  }
  return 0;
}
