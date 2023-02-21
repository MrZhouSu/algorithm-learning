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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k;
  cin >> k;
  for (ll i = 1; i <= k; i++) {
    cout << char('A' + i - 1);
  }
  return (0 ^ 0);
}
