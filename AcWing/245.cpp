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

const int N = 5e5 + 10;

ll n, m;
ll a[N];

struct Node {
  ll l, r;
  ll tmax;  // 最大连续子段和
  ll lmax;  // 最大前缀
  ll rmax;  // 最大后缀
  ll sum;   // 区间和
} tr[N * 4];

void pushup(Node& root, Node& l, Node& r) {
  root.sum = l.sum + r.sum;
  root.lmax = max(l.lmax, l.sum + r.lmax);
  root.rmax = max(r.rmax, r.sum + l.rmax);
  root.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(ll u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(ll u, ll l, ll r) {
  if (l == r)
    tr[u] = {l, r, a[r], a[r], a[r], a[r]};
  else {
    tr[u] = {l, r};
    ll mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}

Node query(ll u, ll l, ll r) {
  if (tr[u].l >= l && tr[u].r <= r) return tr[u];
  ll mid = tr[u].l + tr[u].r >> 1;
  if (r <= mid) {
    return query(u << 1, l, r);
  } else if (l > mid) {
    return query(u << 1 | 1, l, r);
  } else {
    Node tree, left, right;
    left = query(u << 1, l, r);
    right = query(u << 1 | 1, l, r);
    pushup(tree, left, right);
    return tree;
  }
}

void modify(ll u, ll x, ll v) {
  if (tr[u].l == x && tr[u].r == x) {
    tr[u] = {x, x, v, v, v, v};
  } else {
    ll mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)
      modify(u << 1, x, v);
    else
      modify(u << 1 | 1, x, v);
    pushup(u);
  }
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      if (b > c) {
        swap(b, c);
      }
      cout << query(1, b, c).tmax << endl;
    } else {
      modify(1, b, c);
    }
  }
  return (0 ^ 0);
}