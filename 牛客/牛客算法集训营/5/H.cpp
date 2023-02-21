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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x, y, k, n, t;
  cin >> x >> y >> k >> n >> t;

  ll now = 0;
  ll money = 0;

  bool flag = false;

  for (ll i = n; i >= 0; i--) {
    money += x * i;
    now += i;
    if (now > k) {
      x += y * (now / k);
      now = now % k;
    }
    if (money >= t) {
      flag = true;
      cout << n - i + 1 << endl;
      break;
    }
  }

  if (!flag) {
    cout << -1 << endl;
  }

  return (0 ^ 0);
}