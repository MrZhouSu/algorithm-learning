#include <iostream>

using namespace std;

char ch[55];

int main(void) {
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ch[i];

    for (int i = 0; i < n; i++) {
      if (i + 2 < n && ch[i + 2] == '0') {
        if (i + 3 < n && ch[i + 3] == '0') {
          cout << char('a' + ch[i] - '0' - 1);
        } else {
          cout << char('a' - 1 + (ch[i] - '0') * 10 + (ch[i + 1] - '0'));
          i += 2;
        }
      } else {
        cout << char('a' + ch[i] - '0' - 1);
      }
    }
    cout << endl;
  }
  system("pause");
  return 0;
}
