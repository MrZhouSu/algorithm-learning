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
  ll n;
  cin >> n;
  ll x;
  ll sum = 0;
  while (n--) {
    cin >> x;
    if (x & 1) sum++;
  }
  cout << sum << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
