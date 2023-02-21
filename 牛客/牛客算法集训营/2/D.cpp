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

const int N = 2e5 + 10;

ll n;
ll p[N];
ll v[N];
ll cnt[N];
bool visit[N];

void find_cnt(ll j) {
  if (j != 1) {
    if (!visit[p[j]]) {
      visit[p[j]] = true;
      find_cnt(p[j]);
    }
    cnt[j] = cnt[p[j]] + 1;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  p[1] = 1;
  for (ll i = 1; i <= n; i++) cnt[i] = 1;
  for (ll i = 2; i <= n; i++) {
    cin >> p[i];
  }
  visit[1] = true;
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
    find_cnt(i);
  }
  sort(v + 1, v + n + 1);
  sort(cnt + 1, cnt + n + 1);
  ll sum = 0;
  for (ll i = n; i >= 1; i--) {
    sum += v[i] * cnt[i];
  }
  cout << sum << endl;
  return (0 ^ 0);
}