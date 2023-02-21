#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>  //iota
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
const int NN = 1e3 + 10;

ll mmap[NN][NN];

ll n, m;

ll answer[N];

ll run[N], runed[N];

void floyd() {
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      for (ll k = 1; k <= n; k++) {
        mmap[j][k] = min(mmap[j][k], mmap[j][i] + mmap[i][k]);
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  memset(mmap, 0x3f, sizeof mmap);
  cin >> n >> m;
  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    mmap[x][y] = 0;
  }

  floyd();

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (mmap[i][j] == 0) {
        run[i]++;
      } else if (mmap[j][i] == 0) {
        runed[i]++;
      }
    }
  }

  for (ll i = 1; i <= n; i++) {
    if (run[i] + runed[i] == n - 1) {
      answer[runed[i] + 1] = i;
    }
  }

  for (ll i = 1; i <= n; i++) {
    if (!answer[i]) {
      cout << -1 << " \n"[i == n];
    } else {
      cout << answer[i] << " \n"[i == n];
    }
  }

  return (0 ^ 0);
}
