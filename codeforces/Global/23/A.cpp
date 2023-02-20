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

int a[55];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;

  while (t--) {
    ll n, k;
    cin >> n >> k;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i]) flag = true;
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
