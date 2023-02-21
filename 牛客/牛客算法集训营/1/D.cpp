#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
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
  ll x, y, xp, yp;
  cin >> x >> y >> xp >> yp;
  ll s1 = x * y;
  if (xp <= x && yp <= y) {
    cout << max(xp * yp * 1.0 / s1, (x - xp) * (y - yp) * 1.0 / s1) << endl;
  } else if (xp <= x) {
    cout << max(xp * y * 1.0 / (s1 + xp * yp - xp * y),
                ((x - xp) * y * 1.0 / (s1 + (x - xp) * yp - (x - xp) * y)))
         << endl;
  } else if (yp <= y) {
    cout << max(x * yp * 1.0 / (s1 + xp * yp - x * yp),
                (x * (y - yp) * 1.0 / (s1 + xp * (y - yp) - x * (y - yp))))
         << endl;
  } else {
    cout << max(x * y * 1.0 / (xp * yp),
                ((xp - x) * (yp - y) * 1.0) / (xp * yp))
         << endl;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(9);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}