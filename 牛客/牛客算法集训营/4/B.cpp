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

ll n, m;
const int N = 1e5 + 10;

ll a[N], b[N], c[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> c[i];
  }
  bool flag = true;
  for (ll i = 0; i < n; i++) {
    ll sum = (c[i] + c[n - i - 1]);
    ll cha = (c[i] - c[n - i - 1]);
    if (sum % 2 != 0 && m == 2) {
      flag = false;
      break;
    }
    if (cha % 2 != 0 && m == 2) {
      flag = false;
      break;
    }
    if (sum % 2 != 0) {
      sum += m;
    }
    if (cha % 2 != 0) {
      cha += m;
    }
    a[i] = a[n - i - 1] = ((sum / 2) % m + m) % m;
    b[i] = cha / 2;
    b[n - i - 1] = -b[i];
    b[i] = (b[i] % m + m) % m;
    b[n - i - 1] = (b[n - i - 1] + m) % m;
  }
  if (flag) {
    cout << "Yes" << endl;
    for (ll i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    for (ll i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
  } else {
    cout << "No" << endl;
  }

  return (0 ^ 0);
}
