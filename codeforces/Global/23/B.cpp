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

const int N = 1e5 + 10;
int a[N];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int j = n;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) continue;
      while (j >= 1 && a[j]) j--;
      if (i < j) {
        ans++;
        j--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
