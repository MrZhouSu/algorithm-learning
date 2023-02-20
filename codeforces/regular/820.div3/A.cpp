#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, t;

  cin >> t;

  while (t--) {
    cin >> a >> b >> c;

    int time1, time2;
    time1 = a - 1;
    if (b > c)
      time2 = b - 1;
    else
      time2 = c - b + c - 1;
    if (time1 > time2)
      cout << "2" << endl;
    else if (time1 == time2)
      cout << "3" << endl;
    else
      cout << "1" << endl;
  }
  // system("pause");
  return 0;
}
