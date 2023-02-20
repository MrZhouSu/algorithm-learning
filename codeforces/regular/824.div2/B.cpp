#include <iostream>
#include <queue>
#define int long long
using namespace std;

const int N = 110;

int a[N];

signed main(void) {
  int t;

  scanf("%lld", &t);

  while (t--) {
    int n;
    scanf("%d", &n);
    int minid = 1e7 + 10;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      minid = min(minid, a[i]);
    }
    minid *= 2;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int x = 0;
      if (a[i] >= minid) {
        x = a[i] / (minid - 1);
        if ((a[i] % (minid - 1)) == 0) x--;
      }
      res += x;
    }
    printf("%lld\n", res);
  }

  return 0;
}
