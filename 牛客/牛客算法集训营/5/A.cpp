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
ll a[N];
ll b[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  b[0] = a[0];

  for (ll i = 1; i < n; i++) {
    b[i] += b[i - 1] + a[i];
  }

  while (q--) {
    ll k, x;
    cin >> k >> x;
    ll tot = upper_bound(a, a + n, x) - a;
    if (tot - k - 1 >= 0 && tot - 1 >= 0)
      cout << b[tot - 1] - b[tot - k - 1] << endl;
    else if (tot - 1 >= 0)
      cout << b[tot - 1] << endl;
    else
      cout << 0 << endl;
  }

  return (0 ^ 0);
}