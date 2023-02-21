#include <algorithm>
#include <bitset>
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
ll a[N];
ll b[N * 10];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  priority_queue<ll> heap;

  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    heap.push(a[i]);
  }

  for (ll i = 1; i <= N * 10 - 1; i++) {
    ll t = heap.top();
    heap.pop();
    bitset<32> p(t);
    heap.push(p.count());
    b[i] = heap.top();
  }

  while (q--) {
    ll k;
    cin >> k;
    if (k > N * 10 - 1)
      cout << 1 << endl;
    else
      cout << b[k] << endl;
  }

  return (0 ^ 0);
}