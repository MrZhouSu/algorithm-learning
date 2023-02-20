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

const int N = 2e5 + 10;

int a[N];
char str[N];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> str[i];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    ll maxid = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (str[i] == '0' && str[i + 1] == '1') {
        ll minid = a[i + 1];
        ll minID = i + 1;
        for (int j = i + 1; j <= n; j++) {
          if (str[j] == '0') break;
          if (a[j] < minid) {
            minid = a[j];
            minID = j;
          }
        }
        if (a[i] > minid) {
          str[i] = '1';
          str[minID] = '0';
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      maxid += (str[i] - '0') * a[i];
    }
    cout << maxid << endl;
  }
  return 0;
}
