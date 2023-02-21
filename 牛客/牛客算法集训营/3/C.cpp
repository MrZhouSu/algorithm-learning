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

const ll N = 1e5 + 10;

ll n;

ll a[N];

void fun(ll& a1, ll& a2, ll& a3, ll& a4, ll& a5, ll& a6, ll i) {
  a1 = i + 3;
  a2 = i + 4;
  a3 = i + 5;
  a4 = i;
  a5 = i + 1;
  a6 = i + 2;
}

void fun(ll& a1, ll& a2, ll& a3, ll& a4, ll i) {
  a1 = i + 2;
  a2 = i + 3;
  a3 = i;
  a4 = i + 1;
}

void fun(ll& a1, ll& a2, ll& a3, ll& a4, ll& a5, ll i) {
  a1 = i + 2;
  a2 = i + 3;
  a3 = i + 4;
  a4 = i;
  a5 = i + 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  ll x = 0, y = 0;
  bool flag = false;
  for (x = 0; x <= n / 4; x++) {
    for (y = 0; y <= (n - 4 * x) / 5; y++) {
      if ((n - 4 * x - 5 * y) % 6 == 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  for (ll i = 1; i <= 4 * x; i += 4) {
    fun(a[i], a[i + 1], a[i + 2], a[i + 3], i);
  }
  for (ll i = 4 * x + 1; i <= 4 * x + 5 * y; i += 5) {
    fun(a[i], a[i + 1], a[i + 2], a[i + 3], a[i + 4], i);
  }
  for (ll i = 4 * x + 5 * y + 1; i <= n; i += 6) {
    fun(a[i], a[i + 1], a[i + 2], a[i + 3], a[i + 4], a[i + 5], i);
  }
  for (ll i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
  return (0 ^ 0);
}