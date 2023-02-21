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
  ll sum = 0;
  for (ll i = l1; i <= r1; i++) {
    if (n - i <= r2 && n - i >= l2) {
      sum++;
    }
  }
  cout << sum << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}