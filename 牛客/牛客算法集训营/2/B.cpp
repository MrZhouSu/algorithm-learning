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

void solved() {
  ll n, l1, r1, l2, r2;
  cin >> n >> l1 >> r1 >> l2 >> r2;
  if (l1 >= n || l2 >= n) {
    cout << 0 << endl;
    return;
  }
  r1 = min(r1, n - 1);
  r2 = min(r2, n - 1);
  ll rr2 = min(r2, n - l1);
  ll ll2 = max(l2, n - r1);
  ll left = min(r1 - l1 + 1, rr2 - ll2 + 1);
  cout << max(left, 0ll) << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}