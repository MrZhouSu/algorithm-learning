#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

ll a, b;

double mid = 1e9;

double fun(ll mid) { return b * mid + a / sqrt(mid + 1); }

double fun1(ll mid) { return b - 5 / sqrt(mid); }

int main(void) {
  cout << fixed << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b;

  ll x = pow(a / (2 * b), 2.0 / 3) - 1;

  cout << min(fun(x), fun(x + 1)) << endl;

  return 0;
}
