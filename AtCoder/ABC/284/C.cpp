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

const int N = 1000;
ll p[N];
ll find(ll x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  while (m--) {
    ll x, y;
    cin >> x >> y;
    ll px = find(x);
    ll py = find(y);
    if (px != py) {
      p[px] = py;
      n--;
    }
  }
  cout << n << endl;
  return (0 ^ 0);
}
