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

ll n, p;
const int N = 5e3 + 10;
ll a[N];
ll cnt[N];
ll d[N];
ll sum[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> p;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= p;
    cnt[a[i]]++;
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (i != j) d[a[i] * a[j] % p]++;
    }
  }

  for (ll i = 0; i < p; i++) {
    for (ll j = 0; j < p; j++) {
      if (j <= i)
        sum[i] += d[j] * cnt[i - j];
      else {
        sum[i] += d[j] * cnt[p + i - j];
      }
    }
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (i != j) {
        sum[(a[i] * a[j] % p + a[i]) % p]--;
        sum[(a[i] * a[j] % p + a[j]) % p]--;
      }
    }
  }

  for (ll i = 0; i < p; i++) {
    cout << sum[i] << " ";
  }

  return (0 ^ 0);
}