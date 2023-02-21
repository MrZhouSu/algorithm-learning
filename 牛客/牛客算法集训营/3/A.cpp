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
#define lowbit(x) (x) & (-x)
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  ll sum = 0;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    if (x < 0) {
      sum += x;
      continue;
    }
    if (x % 2 == 0) {
      ll y = lowbit(x);
      ll ans = 0;
      while (y) {
        ans++;
        y >>= 1;
      }
      x >>= (ans - 1);
    }
    sum += x;
  }
  cout << sum << endl;

  return (0 ^ 0);
}