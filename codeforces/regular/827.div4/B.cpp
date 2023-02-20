#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
int a[110];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a + n);
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
