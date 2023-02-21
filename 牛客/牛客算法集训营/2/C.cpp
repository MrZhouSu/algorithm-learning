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

const int N = 4e5 + 10;

ll cnt[N];

ll n, m;

const int MOD = 998244353;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll sum = 0;
  cin >> n >> m;
  for (ll i = 1; i <= m; i++) {
    ll l, r;
    cin >> l >> r;
    if (l >= n) {
      continue;
    }
    r = min(r, n - 1);
    cnt[l]++;
    cnt[r + 1]--;
    ll rr2 = min(r, n - l);
    ll ll2 = max(l, n - r);
    ll left = max(min(r - l + 1, rr2 - ll2 + 1), 0ll);
    sum = (sum - left) % MOD;
    // if (n % 2 == 0) {
    //   sum -= 2;
    // }
  }
  for (ll i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (ll i = 1; i <= n; i++) {
    // if (n - i == i) {
    //   sum = (sum + n * (n - 1) / 2) % MOD;
    //   continue;
    // }
    sum = (sum + cnt[i] * cnt[n - i] % MOD) % MOD;
  }

  cout << sum << endl;

  return (0 ^ 0);
}