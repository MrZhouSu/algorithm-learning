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
  ll p;
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      p = i;
      break;
    }
  }
  if (n % (p * p) == 0) {
    cout << p << " " << n / (p * p) << endl;
  } else {
    cout << (ll)sqrt(n / p) << " " << p << endl;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}
