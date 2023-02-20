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
ll n;
void solved() {
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n);
  ll tot = lower_bound(a + 1, a + n, a[0]) - a;
  //   for (ll i = 0; i < n; i++) {
  //     cout << a[i] << ' ';
  //   }
  //   cout << '\n';
  //   if (tot == 0) tot++;
  for (ll i = tot; i < n; i++) {
    if (a[0] < a[i]) {
      a[0] = (a[0] + a[i]) / 2 + ((a[0] + a[i]) & 1);
    }
  }
  cout << a[0] << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
