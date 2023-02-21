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
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (b / 2 == a)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return (0 ^ 0);
}
