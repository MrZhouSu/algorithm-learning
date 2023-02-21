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

char ch[110][110];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> ch[i][j];
    }
  }
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      bool flag = true;
      for (ll k = 0; k < m; k++) {
        if (ch[i][k] == 'x' && ch[j][k] == 'x') {
          flag = false;
          break;
        }
      }
      if (flag) {
        sum++;
      }
    }
  }
  cout << sum;
  return (0 ^ 0);
}
