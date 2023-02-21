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

void solved() {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  ll H = 0;
  for (ll i = 0; i < n; i++) {
    if (!a[i]) continue;
    if (n - i >= a[i]) {
      H += a[i];
      i += a[i];
      i--;
    } else {
      H += n - i;
      break;
    }
  }
  cout << H << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}