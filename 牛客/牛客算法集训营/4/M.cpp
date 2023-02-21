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
ll a[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cout << i % 3 + 1 << " ";
  }

  return (0 ^ 0);
}
