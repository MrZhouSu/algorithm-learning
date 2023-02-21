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
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x1 = a - b + c + d;
  ll y1 = a + b - c + d;
  ll x2 = a + b + c - d;
  ll y2 = b + c + d - a;
  if (x1 % 2 == 0 && y1 % 2 == 0) {
    cout << x1 / 2 << " " << y1 / 2 << endl;
  } else if (x2 % 2 == 0 && y2 % 2 == 0) {
    cout << x2 / 2 << " " << y2 / 2 << endl;
  } else {
    cout << "No Answer!" << endl;
  }

  return (0 ^ 0);
}