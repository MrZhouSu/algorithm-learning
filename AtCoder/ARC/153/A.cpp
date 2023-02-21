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

ll a[15];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  a[1] = a[2] = 1;
  n--;
  if (n != 0) {
    a[8] = n % 10;
    n /= 10;
  }
  if (n != 0) {
    a[7] = a[9] = n % 10;
    n /= 10;
  }
  if (n != 0) {
    a[5] = a[6] = n % 10;
    n /= 10;
  }
  if (n != 0) {
    a[4] = n % 10;
    n /= 10;
  }
  if (n != 0) {
    a[3] = n % 10;
    n /= 10;
  }
  a[1] += n;
  a[2] += n;
  for (ll i = 1; i <= 9; i++) {
    cout << a[i];
  }

  return (0 ^ 0);
}
