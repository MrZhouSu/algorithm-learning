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
  ll suma = 0, sumb = 0, ansa = 5, ansb = 5;
  string str;
  cin >> str;
  for (ll i = 1; i <= 10; i++) {
    ll x = str[i - 1] - '0';
    if (i & 1) {
      suma += x;
      ansa--;
    } else {
      sumb += x;
      ansb--;
    }
    if (suma - sumb > ansb || sumb - suma > ansa) {
      cout << i << endl;
      return;
    }
  }
  if (suma == sumb) {
    cout << -1 << endl;
  } else {
    cout << 0 << endl;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}