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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(16);
  ll x, l, r;
  cin >> x >> l >> r;
  if (x <= l) {
    cout << 0 << endl;
  } else if (x > r) {
    cout << 1 << endl;
  } else {
    cout << (x - l) * 1.0 / (r - l + 1) << endl;
  }

  return (0 ^ 0);
}