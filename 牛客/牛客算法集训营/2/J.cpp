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
ll n;
ll a[N];

void solved() {
  cin >> n;
  ll sum = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
    sum += a[i];
  }
  cout << 2 * n * sum << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}