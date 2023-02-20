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
  ll x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if ((x1 != x2 && x1 != x3 && x2 != x3) ||
      (y1 != y2 && y2 != y3 && y1 != y3)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
