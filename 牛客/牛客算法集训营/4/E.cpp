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

struct Node {
  ll h, v;
  ll value;
  bool operator<(Node& w) { return value < w.value; }
} node[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t, a;
  cin >> n >> t >> a;
  for (ll i = 0; i < n; i++) {
    ll h, v;
    cin >> h >> v;
    v *= t;
    node[i] = {h, v, h * v};
  }

  sort(node, node + n);
  bool flag = true;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (a < node[i].h && node[i].v >= a) {
      flag = false;
      break;
    } else if (node[i].v >= a) {
      cnt++;
    } else {
      cnt++;
      node[i].h -= a;
      if (node[i].h <= 0) {
        continue;
      }
      cnt += (node[i].h + a - node[i].v - 1) / (a - node[i].v);
    }
  }
  if (flag) {
    cout << 1 + t * (cnt - 1) << endl;
  } else {
    cout << -1 << endl;
  }

  return (0 ^ 0);
}
