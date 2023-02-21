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

ll n;
char ch[10];

void solved() {
  ll area = 0;
  cin >> n;
  for (ll i = 0; i < n * n - 1; i++) {
    cin >> ch;
    area += 10;
    for (ll j = 0; j < 4; j++) {
      if (ch[j] == '1') {
        area--;
      } else if (ch[j] == '2') {
        area++;
      }
    }
  }
  cout << n * n * 10 - area << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}