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
  ll va, vb, vc;
  cin >> va >> vb >> vc;
  ll sum = (va + vb + vc) >> 1;
  ll la = sum - va, lb = sum - vb, lc = sum - vc;
  if (vc > lc && vb > lb && va > la && la > 0 && lb > 0 && lc > 0 &&
      (va + vb + vc) % 2 == 0) {
    cout << "Yes" << endl;
    cout << la << " " << lb << " " << lc << endl;
  } else {
    cout << "No" << endl;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
