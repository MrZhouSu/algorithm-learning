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
ll n;

void solved() {
  cin >> n;
  ll x = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    x = __gcd(x, a[i]);
  }
  cout << a[n] / x << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
