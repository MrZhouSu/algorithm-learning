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
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t;
  ll sum = 0;
  cin >> n >> t;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  t = t % sum;
  ll ss = 0;
  for (ll i = 1; i <= n; i++) {
    ss += a[i];
    if (ss > t) {
      cout << i << " " << t - (ss - a[i]) << endl;
      break;
    }
  }
  return (0 ^ 0);
}
