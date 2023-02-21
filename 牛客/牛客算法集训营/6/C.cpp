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

const int N = 1e3 + 10;

const int MOD = 1e9 + 7;

ll a[N];
ll b[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll x = n;
  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

  ll l = 1, r = n;
  ll tot = 1;
  while (l < r) {
    a[l++] = tot;
    a[r--] = tot + 1;
    tot += 2;
  }

  if (n & 1) {
    a[n / 2 + 1] = n;
  }

  for (ll i = 1; i <= n; i++) b[i] = a[i];

  //   for (ll i = 1; i <= n; i++) cout << a[i] << endl;
  while (n != 1) {
    for (ll i = 1; i <= n - 1; i++) {
      a[i] = (a[i] + a[i + 1]) % MOD;
    }
    n--;
  }

  cout << a[1] << endl;

  for (ll i = 1; i <= x; i++) {
    cout << b[i] << " \n"[i == x];
  }

  return (0 ^ 0);
}