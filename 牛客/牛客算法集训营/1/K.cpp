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
  ll n, m;
  cin >> n >> m;
  ll sum0 = n - m;
  ll sum1 = m;
  if (m == n) {
    cout << n - 2 << endl;
    return 0;
  }
  ll sum00 = sum0 >> 1;
  sum0 -= sum00 << 1;
  sum1 -= sum00;
  sum1--;
  if (sum1 < 0) sum1 = 0;
  cout << sum1 << endl;
  // 001 111111111

  return (0 ^ 0);
}