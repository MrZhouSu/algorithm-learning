#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e5 + 10;

int a[N];
int p;
// 1,8 4 1 2 3 4 5 6 7 8
int merge(int l, int r) {
  if (l + 1 == r) {
    if (a[l] > a[r]) {
      int t = a[l];
      a[l] = a[r];
      a[r] = t;
      return 1;
    } else {
      return 0;
    }
  }
  // 78 34 12 56
  int mid = l + r >> 1;
  // cout << mid << endl;
  int a1 = merge(l, mid);
  int a2 = merge(mid + 1, r);
  if (a[l] > a[mid + 1]) {
    for (int i = l; i <= mid; i++) {
      int t = a[i];
      a[i] = a[mid + 1 + i - l];
      a[mid + 1 + i - l] = t;
    }
    return a1 + a2 + 1;
  } else {
    return a1 + a2;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    cin >> p;
    for (int i = 1; i <= p; i++) {
      cin >> a[i];
    }
    if (p == 1) {
      cout << 0 << endl;
      continue;
    }
    int x = merge(1, p);
    bool flag = true;
    for (int i = 1; i <= p; i++) {
      if (a[i] != i) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << x << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
