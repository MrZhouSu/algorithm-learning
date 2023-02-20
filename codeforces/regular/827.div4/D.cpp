#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    vector<int> a(1010, 0);
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      a[x] = max(a[x], i);
    }
    int maxid = -1;
    for (int i = 1; i <= 1000; i++) {
      for (int j = 1; j <= 1000; j++) {
        if (a[i] && a[j] && gcd(i, j) == 1) maxid = max(maxid, a[i] + a[j]);
      }
    }
    cout << maxid << endl;
  }
  return 0;
}
