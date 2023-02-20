#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
#define PII pair<ll, ll>

ll a[200010];
PII b[200010];
bool cmp(PII &a, PII &b) { return a.second < b.second; }
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    ll n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
      cin >> b[i].first;
      b[i].second = i;
    }

    sort(b + 1, b + q + 1);
    ll sum = 0;
    int line = 1;
    for (int i = 1; i <= n;) {
      if (b[line].first < a[i]) {
        b[line].first = sum;
        line++;
        if (line > q) break;
      } else {
        sum += a[i];
        i++;
      }
    }
    if (line <= q) {
      for (int i = line; i <= q; i++) {
        b[i].first = sum;
      }
    }
    sort(b + 1, b + q + 1, cmp);
    for (int i = 1; i <= q; i++) {
      cout << b[i].first << " \n"[i == q];
    }
  }
  return 0;
}
