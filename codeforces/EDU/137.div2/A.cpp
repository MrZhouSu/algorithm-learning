#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

int a[10];
ll c[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  c[1] = 1;
  c[0] = 1;
  for (int i = 2; i <= 9; i++) {
    c[i] = c[i - 1] * i;
  }

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    ll x = 10 - n;
    // CX2*6
    cout << c[x] / (2 * c[x - 2]) * 6 << endl;
  }
  return 0;
}
