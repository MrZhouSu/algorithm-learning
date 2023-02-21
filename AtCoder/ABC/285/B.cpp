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

char str[5010];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n >> str + 1;
  for (ll i = 1; i < n; i++) {
    ll k = 1;
    while (k + i <= n) {
      if (str[k] == str[k + i]) {
        k--;
        break;
      }
      k++;
    }
    cout << min(k, n - i) << endl;
  }

  return (0 ^ 0);
}
