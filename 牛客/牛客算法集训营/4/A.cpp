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
  ll x, y;
  cin >> x >> y;
  double lnx = log(x);
  double lny = log(y);
  if (y * lnx > x * lny) {
    cout << x << endl;
  } else if (x * lny > y * lnx) {
    cout << y << endl;
  } else {
    cout << min(x, y) << endl;
  }

  return (0 ^ 0);
}
