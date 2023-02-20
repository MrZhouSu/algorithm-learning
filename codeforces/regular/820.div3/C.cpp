#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define PII pair<int, int>
const int N = 2e5 + 10;
PII p[N];
char ch[N];

bool cmp(PII &a, PII &b) { return a.first > b.first; }
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;

  cin >> t;

  while (t--) {
    cin >> ch;
    int n = strlen(ch);
    for (int i = 0; i < n; i++) {
      p[i].first = ch[i] - 'a' + 1;
      p[i].second = i + 1;
    }
    int ans = 1;
    if (p[0].first > p[n - 1].first) {
      sort(p + 1, p + n - 1, cmp);
      for (int i = 1; i < n - 1; i++) {
        if (p[i].first <= p[0].first && p[i].first >= p[n - 1].first) ans++;
      }
      cout << p[0].first - p[n - 1].first << " " << ans + 1 << endl;
      cout << 1 << " ";
      for (int i = 1; i < n - 1; i++) {
        if (p[i].first <= p[0].first && p[i].first >= p[n - 1].first)
          cout << p[i].second << " ";
      }
      cout << n << endl;
    } else {
      sort(p + 1, p + n - 1);
      for (int i = 1; i < n - 1; i++) {
        if (p[i].first <= p[n - 1].first && p[i].first >= p[0].first) ans++;
      }
      cout << p[n - 1].first - p[0].first << " " << ans + 1 << endl;
      cout << 1 << " ";
      for (int i = 1; i < n - 1; i++) {
        if (p[i].first <= p[n - 1].first && p[i].first >= p[0].first)
          cout << p[i].second << " ";
      }
      cout << n << endl;
    }
  }
  system("pause");
  return 0;
}
