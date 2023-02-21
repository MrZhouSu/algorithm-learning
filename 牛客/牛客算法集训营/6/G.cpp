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

const int N = 2e5 + 10;
ll a[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  for (ll i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);

  ll sum = 0;

  ll l = 1, r = n;

  for (ll i = 0; i < k; i++) {
    if (a[l] * a[l + 1] < a[r] * a[r - 1]) {
      sum += a[l] * a[l + 1];
      l += 2;
    } else {
      sum += a[r] * a[r - 1];
      r -= 2;
    }
  }

  cout << sum << endl;

  return (0 ^ 0);
}