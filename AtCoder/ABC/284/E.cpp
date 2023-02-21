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

const int N = 2e5 + 10;
ll h[N], e[N * 2], ne[N * 2], idx;
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

ll sum = 0;
bool visit[N];

void dfs(ll v) {
  visit[v] = true;
  for (ll i = h[v]; ~i; i = ne[i]) {
    ll j = e[i];
    if (!visit[j]) {
      dfs(j);
      sum++;
      if (sum > 1000000) return;
    }
  }
  visit[v] = false;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  dfs(1);
  cout << min(sum + 1, (ll)1000000) << endl;
  return (0 ^ 0);
}
