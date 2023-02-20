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
#define PII pair<int, int>
using namespace std;

const int N = 1e5 + 10;

ll a[N];
ll n;
PII aw[N];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {
    memset(aw, 0, sizeof aw);
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    // RMQ();
    // int mm = 0;
    ll maxid = a[1];
    ll line = 0;
    for (int i = 1; i < n; i++) {
      // while ((1 << k + 1) <= sum)
      //     k++;
      // int maxid = max(maxsum[1][k], maxsum[i - (1 << k) + 1][k]);
      if (a[i] > a[i + 1]) {
        ll ans = a[i] - a[i + 1];
        aw[line++] = {ans, i + 1};
        // mm = max(mm, ans);
      }
    }
    sort(aw, aw + line);
    for (int i = 1; i <= n - line; i++) {
      cout << 1 << " ";
    }
    for (int i = 0; i < line; i++) {
      cout << aw[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}
