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
  ll x;
  cin >> x;
  if (x <= 7 && x >= 1) {
    cout << "very easy" << endl;
  } else if (x <= 233) {
    cout << "easy" << endl;
  } else if (x <= 10032) {
    cout << "medium" << endl;
  } else if (x <= 114514) {
    cout << "hard" << endl;
  } else if (x <= 1919810) {
    cout << "very hard" << endl;
  } else {
    cout << "can not imagine" << endl;
  }

  return (0 ^ 0);
}